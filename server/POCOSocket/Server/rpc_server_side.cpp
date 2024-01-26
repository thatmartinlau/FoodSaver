#include <iostream>
#include "common_characteristics.hpp"

#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "rpc/server.h"
#include "rpc/client.h"
#include "rpc/this_handler.h"
#include "rpc/this_session.h"

using namespace std;



//Database storage files: no touchy :)) Except if you wihs totest fully: change to YOUR absolute file path.
const string Database_simple_data = "C:/Users/adamn/OneDrive/Desktop/L'X School/FoodSaver/server/POCOSocket/Server/databases/database_simple_data.csv"; //               Stores: username, password, display_na, telegram_name, gender, promo, address, phone_num, tele_notif, mkt_notif
const string Database_offer_list_data = "C:/Users/adamn/OneDrive/Desktop/L'X School/FoodSaver/server/POCOSocket/Server/databases/database_offer_list_data.csv"; //       Stores: username, ingr1_name, 4 others, price,ingr2_name, 4 others, price2, etc...
const string Database_fridge_and_food_lists_data = "C:/Users/adamn/OneDrive/Desktop/L'X School/FoodSaver/server/POCOSocket/Server/databases/database_fridge_data.csv"; //Stores: username, fridge as ingr1_name, 4 others, ingr2_name, 4 others, etc. On new line, stores dietary restrictions as 0,1,0 etc...
const string Database_recipe_data = "C:/Users/adamn/OneDrive/Desktop/L'X School/FoodSaver/server/POCOSocket/Server/databases/database_recipe_data.csv"; //stores recipes, indexed by $ as separator.
//FILE FORMATS:

//Ingredients: vector<string>> as [ingredient_name, expiry_date, quantity, category, priority_level;
//Fridge: vector<vector<string>>
//Offer: vector<vector<string>>>: [Ingredient, [price]]
//Offer List: vector<vector<vector<string>>>, looking like {Offer1, Offer2, etc}.
//Database: unordered_map<string, UserData>, dicts as [], looking like  {username1: UserData, username2: UserData}, with UserData having:


class UserData {
public:
    UserData(string password, basic_user_data basic_us_data) {
        basic_u_data = basic_us_data;
    }

    UserData(string password){
        this->password = password;
    }
    UserData() {}
    ~UserData() {}
    string password;
    basic_user_data basic_u_data;
    list<bool> food_and_dietary_restrictions;    
    vector<vector<string>> fridge; //Implied: ingredient is vector<string>, still. Good luyck coding guys!    
    vector<vector<vector<string>>> offer_list; //Implied: offer is [Ingredient, [price]]. Offer list is vector of this offer type.
};


//DATABASE declaration
unordered_map<string, UserData>* database = new unordered_map<string, UserData>;
vector<string>* recipes_list = new vector<string>;


//needs to be a char: predefined or buggy, somehow.
char csv_sep = *","; //Replaces comma. Convention to use comma in comments. Same for the below.
char recipes_sep = *"$"; //Separator for long files. Of text, for recipes.

void read_simple_types_from_csv() {
    ifstream file;
    file.open(Database_simple_data);
    vector<string> lines;
    for (string line_it; getline(file, line_it);) {
        lines.push_back(line_it);
    }
    
    for (auto line_it: lines) { //iterate through each user, add up all the factors into UserData , into database.
        vector<string> user_data;
        
        stringstream line_it_stream(line_it);
        for (string line_it_elt; getline(line_it_stream, line_it_elt, csv_sep);) {
            user_data.push_back(line_it_elt);
        }
        //fill basic user data, with all types
        basic_user_data basic_u_data;
        basic_u_data.display_name = user_data[2];
        basic_u_data.telegram_username = user_data[3];
        basic_u_data.gender = std::stoi(user_data[4]); //convert to int
        basic_u_data.promotion = std::stoi(user_data[5]); //convert to int
        basic_u_data.building_address = user_data[6];
        basic_u_data.phone_number = std::stoi(user_data[7]); //convert to int
        basic_u_data.telegram_notifications = std::stoi(user_data[8]); //convert to int
        basic_u_data.marketplace_notifications = std::stoi(user_data[9]);//convert to int
        
        (*database)[user_data[0]] = UserData(user_data[1], basic_u_data); //0 is username, 1 is password, rest is U-data.
    }
    file.close();
}


void read_fridge_and_food_lists_from_csv() { //call AFTER simple_types, before offer_list_from_csv. Remember to call
    ifstream file;
    file.open(Database_fridge_and_food_lists_data);
    string username;
    int count = 0;
    for (string line; getline(file, line);) {
        stringstream line_stream(line);
        vector<string> line_data;
        for (string element; getline(line_stream, element, csv_sep);) {
            line_data.push_back(element);
        }
        if (count % 2 == 0) {
            username = line_data[0];
            for (int i = 1; i < line_data.size(); i +=5) {
                vector<string> ingredient;
                for (int j = 0; j < 5; j ++) {
                        ingredient.push_back(line_data[i + j]);
                }
                (*database)[username].fridge.push_back(ingredient);
            }
            count += 1;
        }
        else { //odd number, store food_and_dietary_restrictions:
            for (int i=0; i < line_data.size(); i++) {
                (*database)[username].food_and_dietary_restrictions.push_back(std::stoi(line_data[i]));
            }
            count += 1;
        }
    }
    file.close();
}


void read_offer_list_from_csv() {
    ifstream file;
    file.open(Database_offer_list_data);
    for (string line; getline(file, line);) {
        stringstream line_stream(line);
        vector<string> line_data;
        for (string element; getline(line_stream, element, csv_sep);) {
            line_data.push_back(element);
        }
        string username = line_data[0];
        for (vector<string>::iterator it=line_data.begin() + 1; it != line_data.end(); it+= 6) {
            vector<vector<string>> offer;
            vector<string> ingredient; //three are all necessary.
            vector<string> price;
            for (int j=0; j <5; j++) {
                ingredient.push_back(*next(it, j));
            }
            price.push_back(*next(it, 5));
            offer.push_back(ingredient);
            offer.push_back(price);
            (*database)[username].offer_list.push_back(offer);
        }
        
    }
    file.close();
}

void read_recipes_from_csv() {
    ifstream file;
    file.open(Database_recipe_data);
    vector<string> recipes;
    for (string long_str; getline(file, long_str, recipes_sep);) {
        recipes.push_back(long_str);
    }
    recipes_list->insert(recipes_list->end(), recipes.begin(), recipes.end());
}


void read_from_csv() {
    //first, read simple types for username / password. And this allows us to create UserData.
    read_simple_types_from_csv();//we begin here, initialize user class. Then, we initialise fridge and offer_list types. Along with food restrictions.
    read_fridge_and_food_lists_from_csv(); //use already initialized database. 
    read_offer_list_from_csv();
    read_recipes_from_csv();
}



//Write to files
void write_simple_types() {
    ofstream file;
    file.open(Database_simple_data);
    for (const auto& [username, user_data]: *database) {
        vector<string> user_values_in_string_format;
        user_values_in_string_format.push_back(username);
        user_values_in_string_format.push_back(user_data.password);
        user_values_in_string_format.push_back(user_data.basic_u_data.display_name);
        user_values_in_string_format.push_back(user_data.basic_u_data.telegram_username);
        user_values_in_string_format.push_back(std::to_string(user_data.basic_u_data.gender));
        user_values_in_string_format.push_back(std::to_string(user_data.basic_u_data.promotion));
        user_values_in_string_format.push_back(user_data.basic_u_data.building_address);
        user_values_in_string_format.push_back(std::to_string(user_data.basic_u_data.phone_number));
        user_values_in_string_format.push_back(std::to_string(user_data.basic_u_data.telegram_notifications));
        user_values_in_string_format.push_back(std::to_string(user_data.basic_u_data.marketplace_notifications));
        string writing_to_file_line;
        for (vector<string>::iterator it = user_values_in_string_format.begin(); it != user_values_in_string_format.end(); ++it) {
            writing_to_file_line.append(*it + csv_sep);
        }
        if (!writing_to_file_line.empty()) //stolen fron SToflow, username jcrv
            writing_to_file_line.pop_back();
        file << writing_to_file_line << endl;
    }
    file.close();
}

void write_fridge_and_food_lists() {
    ofstream file;
    file.open(Database_fridge_and_food_lists_data);
    for (const auto& [username, user_data] : *database) {
        vector<string> first_line_to_write = {username};
        for (int i=0; i < user_data.fridge.size(); i++) {
                vector<string> ingredient = user_data.fridge[i];
                for (int j=0; j < 5; j++) {
                    first_line_to_write.push_back(ingredient[j]);
                    
                }
        }
        string line_to_write_here;
        for (vector<string>::iterator it = first_line_to_write.begin(); it != first_line_to_write.end(); it++) {
            line_to_write_here.append(*it + csv_sep);
        }
        if (!line_to_write_here.empty()) //stolen fron SToflow, username jcrv
            line_to_write_here.pop_back();        file << line_to_write_here << endl;

        //second line is writing boolean restrictions into file.
        string line2; 
        for (list<bool>::const_iterator it = user_data.food_and_dietary_restrictions.begin(); it != user_data.food_and_dietary_restrictions.end(); it++) {
            line2.append(to_string(*it) + csv_sep); //outputs "0" or "1" in string repr.
        }
        if (!line2.empty()) //stolen fron SToflow, username jcrv
            line2.pop_back();
        file << line2 << endl;
    }
    file.close();
}

void write_offer_list() {
    ofstream file;
    file.open(Database_offer_list_data);
    for (const auto& [username, user_data] : *database) {
        vector<string> line_to_write = {username};
        for (int i=0; i < user_data.offer_list.size(); i++) {
            for (int j=0; j < 5; j ++) {
                line_to_write.push_back(user_data.offer_list[i][0][j]);
            }
            line_to_write.push_back(user_data.offer_list[i][1][0]); //price is indexed as 0th element of a vector<string> in a vec<vec<string>>
        }
        string line_to_write_string;
        for (vector<string>::iterator it = line_to_write.begin(); it != line_to_write.end(); it++) {
            line_to_write_string.append(*it + csv_sep);
        }
        if (!line_to_write_string.empty()) //stolen fron SToflow, username jcrv
            line_to_write_string.pop_back();        
        file << line_to_write_string << endl;
    }
    file.close();
}

void write_recipes_list() {
    ofstream file;
    file.open(Database_recipe_data);
    for (vector<string>::iterator i = recipes_list->begin(); i != recipes_list->end()-1; i++) {
        file << *i << recipes_sep;
    }
    file << *(recipes_list->end() -1);
    file.close();
}


void write_to_csv() {
    write_simple_types();
    write_fridge_and_food_lists();
    write_offer_list();
    write_recipes_list();
}


void init_data_test() { //debug function. Tests database read/write all together along with test_read_write_csv().
    UserData data;
    string m = "Molly";
    
    data.password = "Darton";
    vector<vector<string>> fridge_darton;
    vector<string> apple;
    string name = "apple", category = "cat1", qty="3", expiry = "22.10.2024", priority_level = "RED";
    apple.push_back(name); apple.push_back(expiry); apple.push_back(qty); apple.push_back(category); apple.push_back(priority_level);
    vector<string> apple2;
    string name2 = "apple2", category2 = "cat2", qty2="1", expiry2 = "22.10.2026", priority_level2 = "RED";
    apple2.push_back(name2); apple2.push_back(expiry2); apple2.push_back(qty2); apple2.push_back(category2); apple2.push_back(priority_level2);
    fridge_darton.push_back(apple); fridge_darton.push_back(apple2);
    data.fridge = fridge_darton;
    list<bool> restrictions_of_molly = {0,1,1,0,0};
    list<bool> restrictions_of_johnny = {1,1,1,0,1};
    vector<vector<string>> offer2;
    offer2.push_back(data.fridge[1]);
    string price_str_2 = "10";
    vector<string> price_2;
    price_2.push_back(price_str_2);
    offer2.push_back(price_2);
    data.offer_list.push_back(offer2);
    data.food_and_dietary_restrictions = restrictions_of_molly;
    
    (*database)[m] = data;
    
    string k = "Johnny";
    vector<vector<string>> offer;
    offer.push_back(data.fridge[0]);
    string price_str = "10";
    vector<string> price;
    price.push_back(price_str);
    offer.push_back(price);
    data.offer_list.push_back(offer);
    data.food_and_dietary_restrictions = restrictions_of_johnny;
    (*database)[k] = data;
    
    //add simple recipes:
    (*recipes_list)[0] = "hello, this is a recipe!";
    (*recipes_list)[1] = "recipe2";
    
}

int test_read_csv() {
    init_data_test();
    write_to_csv();
    read_from_csv();
    cout << "blabla";
    //find a way to open database,f rom debug, if you want to use read_from_csv() and it doesn't work. Reportto Adam :thumbs-Up:
    return 1;
}
//int val2 = test_read_csv();


//.////Actual Live Server Stuff:

//DB Manipulation functions:



void add_user(string username, string password){
    if (database->find(username) == database->end()) {
        // Element doesn't exist, so add it
        UserData data(password);
        (*database)[username] = data;
    }
}

void remove_user(string username, string password){
    auto el = database->find(username); // Find the username in the database
    if (el != database->end()) {
        // Username exists
        if (password == el->second.password) {
            // Password matches
            database->erase(el); // Remove the user if the password matches
        } else {
            // Password does not match
            auto err_obj = std::make_tuple(507, "Incorrect Password");
            rpc::this_handler().respond_error(err_obj);
        }
    } else {
        // Username not found
        auto err_obj = std::make_tuple(123, "Username not found");
        rpc::this_handler().respond_error(err_obj);
    }
}

void update_user(string old_username, string old_password, string new_username, string new_password) {
    auto el = database->find(old_username); // Find the old username in the database

    if (el != database->end() && old_password == el->second.password) {
        // Username exists and password matches

        // Create a new entry with the updated username and password
        UserData new_data(new_password);
        database->emplace(new_username, std::move(new_data));

        // Remove the old entry
        database->erase(el);
    }
    else if(old_password != el->second.password){
        // Password does not match
        auto err_obj = std::make_tuple(507, "Incorrect Password");
        rpc::this_handler().respond_error(err_obj);
    }
 else {
    // Username not found
    auto err_obj = std::make_tuple(123, "Username not found");
    rpc::this_handler().respond_error(err_obj);
}
    
}

void update_user_characteristics(string username, string password, vector<string> new_characs) {
    auto el = database->find(username);
    
    if (el != database->end() && password==el->second.password) {
        basic_user_data new_user_data;
    new_user_data = deserialize_basic_data_of_user(new_characs);
        el->second.basic_u_data = new_user_data;
    }
    else if(password != el->second.password){
            // Password does not match
            auto err_obj = std::make_tuple(507, "Incorrect Password");
            rpc::this_handler().respond_error(err_obj);
    }
else {
        // Username not found
        auto err_obj = std::make_tuple(123, "Username not found");
        rpc::this_handler().respond_error(err_obj);
    }
    
}

void update_fridge(string username, string password, vector<string> fridge) {
    vector<vector<string>> new_fridge = deserialize_fridge(fridge);
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
                // Password matches
            vector<vector<string>> old_data = el->second.fridge; //used so we can later delete the old data
            el->second.fridge = std::move(new_fridge);

            old_data.clear();

            std::vector<std::vector<std::string>>().swap(old_data);//releases the memory used by old_data
            }
            else if(password != el->second.password){
            // Password does not match
            auto err_obj = std::make_tuple(507, "Incorrect Password");
            rpc::this_handler().respond_error(err_obj);
            }
            else {
            // Username not found
            auto err_obj = std::make_tuple(123, "Username not found");
            rpc::this_handler().respond_error(err_obj);
            }

        }
} //updates a user fridge

void update_offer(std::string username, string password, vector<string> offer) {
        vector<vector<vector<string>>> new_offer = deserialize_offer_list(offer);
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
            // Password matches
            vector<vector<vector<string>>> old_data = el->second.offer_list; //used so we can later delete the old data
            el->second.offer_list = std::move(new_offer);

            old_data.clear();

           vector<vector<vector<string>>>().swap(old_data);//releases the memory used by old_data

            }
            else if(password != el->second.password){
            // Password does not match
            auto err_obj = std::make_tuple(507, "Incorrect Password");
            rpc::this_handler().respond_error(err_obj);
            }
            else {
            // Username not found
            auto err_obj = std::make_tuple(123, "Username not found");
            rpc::this_handler().respond_error(err_obj);
            }
        }
} //updates a user offer list

void addRecipes(const vector<string> new_recipes) {
        for (const string& recipe : new_recipes) {
            recipes_list->push_back(recipe);
        }
}//adds recipes

//DB Sending Functions:
vector<string> get_offer_list(string username, string password) {

        auto el = database->find(username); // Find the username in the database

        if (el != database->end() && password == el->second.password) {
            // Username exists and password matches

            // Move the offer_list content to the caller
	    return serialize_offer_list(std::move(el->second.offer_list));
        }


        return {}; // Return an empty offer_list if no username or password does not match

}
vector<string> get_fridge(string username, string password) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end() && password == el->second.password) {
            // Username exists and password matches


             return serialize(std::move(el->second.fridge));
        }


        else { // Return an empty offer_list if no username or password does not match
             vector<string> empty_return_vector = {"Empty, error when coding"};
             return empty_return_vector;
        }

}

vector<string> getMapOfOffers(){
        unordered_map<string, vector<vector<vector<string>>>> offerMap;

        // Iterating through the database to retrieve user offers
        for (const auto& entry : *database) {
            const std::string& username = entry.first;
            const UserData& userData = entry.second;

            // Fetching offers for the current user from UserData
            const std::vector<std::vector<std::vector<std::string>>>& userOffers = userData.offer_list;

            // Assigning the user offers to the offerMap using the username as the index
            offerMap[username] = userOffers;
        }

        return serialize_unMap(offerMap);
}


vector<string> get_user_name_vectors() {
        vector<string> user_list;
        for (auto& [key, value] : *database) {
            user_list.push_back(key);
        }
        return user_list;
}

vector<string> getAllRecipes() {
        vector<string> all_recipes;
        if (recipes_list != nullptr) {
            for (const string& recipe : *recipes_list) {
            all_recipes.push_back(recipe);
            }
        }
        return all_recipes;
}


// for food and dietary_restrictions
vector<string> get_user_food_restrictions(string username, string password) {
        auto el = database->find(username); // Find the username in the database

        if (el != database->end() && password == el->second.password) {
            // Username and password match correctly
            list<bool> food_and_dietary_restrictions = el->second.food_and_dietary_restrictions;
            std::vector<std::string> vector_string_restrictions;

            for (bool value : food_and_dietary_restrictions) {
            vector_string_restrictions.push_back(std::to_string(value));
            }

            return vector_string_restrictions;

        }
        else {
            vector<string> empty_return_vector = {"Empty, error when coding"};
            return empty_return_vector;
        }
}


vector<string> get_user_characteristics(string username, string password) {
    auto el = database->find(username); // Find the username in the database
    
    if (el != database->end() && password == el->second.password) {
        // Username and password match correctly
        return serialize_basic_data_of_user(el->second.basic_u_data);   
    }
    else {
        vector<string> empty_return_vector = {"Empty, error when coding"};
        return empty_return_vector;
    }
    
}


//check functions:
double check_user(string username, string password) {
        if (database->find(username) != database->end()) {
            //check password matches
            if ((*database)[username].password == password) {
                return 1;
            }
        }
        else {
            return 0;
        }
}



//Testing functions
//void test_sending_fridges(vector_of_ingredients fridge) {
//    cout << fridge[0].name << fridge[0].quantity << endl;
//}

vector<string> test_sending_ingredient_as_vec(vector<string> ingredient) {
    cout << ingredient[0] << ingredient[0] << endl;
    return ingredient;
}

vector<vector<string>> test_sending_fridge_as_vec(vector<vector<string>> fridge) {
    cout << fridge[0][0] << fridge[1][1] << endl;
    return fridge;
}





int main() {
    rpc::server srv(8080);
    
    
    //DB Manip/add/remove
    srv.bind("add_user", &add_user);
    srv.bind("remove_user", &remove_user);
    srv.bind("update_user", &update_user);

    srv.bind("update_user_characteristics", &update_user_characteristics);
    
    srv.bind("update_fridge", &update_fridge);
    srv.bind("update_offer", &update_offer);
    
    //DB Sending
    srv.bind("get_fridge", &get_fridge);
    srv.bind("get_offer_list", &get_offer_list);
    
    //General Functions
    srv.bind("getMapOfOffers", &getMapOfOffers);
    srv.bind("get_user_name_vectors", &get_user_name_vectors);
    srv.bind("addRecipes", &addRecipes);
    srv.bind("getAllRecipes", &getAllRecipes);
    
    srv.bind("get_user_food_restrictions", &get_user_food_restrictions);
    srv.bind("get_user_characteristics", &get_user_characteristics);
    //Check functions:
    srv.bind("check_user", &check_user);
    
    
    //binding test functions:
    //srv.bind("test_sending_fridge_as_vec", &test_sending_fridge_as_vec);
    //srv.bind("test_sending_ingredient_as_vec", &test_sending_ingredient_as_vec);
    
    
    //SERVER running from here:
    read_from_csv();
    cout << "running" << endl;        
    srv.run();
        
    return 0;    
}
