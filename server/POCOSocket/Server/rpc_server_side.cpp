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



//Database storage files: no touchy :))
const string Database_simple_data = "databases/database_simple_data.csv"; //               Stores: username, password, display_na, telegram_name, gender, promo, address, phone_num, tele_notif, mkt_notif
const string Database_offer_list_data = "databases/database_offer_list_data.csv"; //       Stores: username, ingr1_name, 4 others, price,ingr2_name, 4 others, price2, etc...
const string Database_fridge_and_food_lists_data = "databases/database_fridge_data.csv"; //Stores: username, fridge as ingr1_name, 4 others, ingr2_name, 4 others, etc. On new line, stores dietary restrictions as - newline
//as 0,1,0,1,0,1,1 checkbox integers for booleans.
//FILE FORMATS:

//Ingredients: vector<string>>
//Fridge: vector<vector<string>>
//Offer: vector<vector<string>>>: with vectors represented as {}, an offer looks like: {Ingredient1, {price}} where all elements are strings.
//Offer List: <vector<vector<vector<string>>>>, looking like {Offer1, Offer2, etc}.
//Database: unordered_map<string, UserData>, dicts as [], looking like  {username1: UserData, username2: UserData}, with UserData having:


class UserData {
public:
    UserData(string password, basic_user_data basic_u_data) {
        display_name = basic_u_data.display_name;
        telegram_username = basic_u_data.telegram_username;
        gender = basic_u_data.gender;
        promotion = basic_u_data.promotion;
        building_address = basic_u_data.building_address;
        phone_number = basic_u_data.phone_number;
        food_and_dietary_restrictions = basic_u_data.food_and_dietary_restrictions;
        telegram_notifications = basic_u_data.telegram_notifications;
        marketplace_notifications = basic_u_data.marketplace_notifications;
    };
    UserData(string password){
        this->password = password;
    };
    UserData() {}
    ~UserData() {}
    string password;
    string display_name;
    string telegram_username;
    int gender;
    int promotion;
    string building_address;
    int phone_number;
    int telegram_notifications;
    int marketplace_notifications;
    list<bool> food_and_dietary_restrictions;
    vector<vector<string>> fridge; //Implied: ingredient is vector<string>, still. Good luyck coding guys!    
    vector<vector<vector<string>>> offer_list; //Implied: offer is [Ingredient, [price]]. Offer list is vector of this offer type.
};


//DATABASE declaration
unordered_map<string, UserData>* database = new unordered_map<string, UserData>;




//some needs for delimiter type within getline():
char basic_csv_separator = (char) 9; //Replaces comma. Convention to use comma in comments. Same for the below.
char ingr_separator_in_fridge = *"~";  //Replaces semicolon, for [];[] where [] are ingredients.
char separator_within_ingredient = *"*"; //replacing colon for {name:category:quantity...etc} within an ingredient.
char separator_within_offer_list = *">"; //replaces / sign, separating offers. 

//some needs for string comparison, since cpp doesn't accept strings to be "{}" without them being called a string befrehand.
string square_brackets_sep = "[]"; 
string curly_brackets_sep =  "{}"; 
string absolute_signs_sep = "||";

//Storage format: username, password, fridge, offer;
//Inspired from iq.opengenus.org/read-and-write-in-csv-cpp/. I adapted the main idea from them. #Adam

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
        for (string line_it_elt; getline(line_it_stream, line_it_elt, basic_csv_separator);) {
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
        //basic_user_data's list<bool> taken out in fridge_from_csv function.
        basic_u_data.telegram_notifications = std::stoi(user_data[8]); //convert to int
        basic_u_data.marketplace_notifications = std::stoi(user_data[9]);//convert to int
        
        (*database)[user_data[0]] = UserData(user_data[1], basic_u_data); //0 is username, 1 is password, rest is U-data.
    }
}



void read_fridge_and_food_lists_from_csv() { //call AFTER simple_types, before offer_list_from_csv. Remember to call
    ifstream file;
    file.open(Database_fridge_and_food_lists_data);
    string username;
    int count = 0;
    for (string line; getline(file, line);) {
        stringstream line_stream(line);
        vector<string> line_data;
        for (string element; getline(line_stream, element, basic_csv_separator);) {
            line_data.push_back(element);
        }
        if (count % 2 == 0) {
            username = line_data[0];
            for (int i = 1; i < sizeof(line_data); i +=5) {
                vector<string> ingredient;
                for ( int j = 1; j < 5; j ++) {
                    ingredient.push_back(line_data[i + j]);
                }
                (*database)[username].fridge.push_back(ingredient);
            }
        }
        else { //odd number, store food_and_dietary_restrictions:
            for (int i=0; i < sizeof(line_data); i++) {
                (*database)[username].food_and_dietary_restrictions.push_back(std::stoi(line_data[i]));
            }
        }
    }
}
void read_offer_list_from_csv() {
    ifstream file;
    file.open(Database_offer_list_data);
    for (string line; getline(file, line);) {
        stringstream line_stream(line);
        vector<string> line_data;
        vector<vector<vector<string>>> offer_list;
        for (string element; getline(line_stream, element, basic_csv_separator);) {
            line_data.push_back(element);
        }
        string username = line_data[0];
        for (vector<string>::iterator it=line_data.begin() + 1; it != line_data.end(); it+= 6) {
            vector<vector<string>> offer;
            vector<string> ingredient; //three are all necessary.
            vector<string> price;
            for ( int j=0; j <5; j++ ) {
                ingredient.push_back(*next(it, j));
            }
            price.push_back(*next(it, 6));
            offer.push_back(ingredient);
            offer.push_back(price);
            (*database)[username].offer_list.push_back(offer);
        }
        
    }
}


void read_from_csv() {
    //first, read simple types for username / password. And this allows us to create UserData.
    read_simple_types_from_csv();//we begin here, initialize user class. Then, we initialise fridge and offer_list types. Along with food restrictions.
    read_fridge_and_food_lists_from_csv(); //use already initialized database. 
    read_offer_list_from_csv();
    cout << "Read!";
}


void write_simple_types() {
    ofstream file;
    for (const auto& [username, user_data]: *database) {
        vector<string> user_values_in_string_format;
        user_values_in_string_format.push_back(username);
        user_values_in_string_format.push_back(user_data.display_name);
        user_values_in_string_format.push_back(user_data.telegram_username);
        user_values_in_string_format.push_back(std::to_string(user_data.gender));
        user_values_in_string_format.push_back(std::to_string(user_data.promotion));
        user_values_in_string_format.push_back(user_data.building_address);
        user_values_in_string_format.push_back(std::to_string(user_data.phone_number));
        user_values_in_string_format.push_back(std::to_string(user_data.telegram_notifications));
        user_values_in_string_format.push_back(std::to_string(user_data.marketplace_notifications));
        string writing_to_file_line;
        for (vector<string>::iterator it = user_values_in_string_format.begin(); it != user_values_in_string_format.end(); ++it) {
            writing_to_file_line.append(*it + basic_csv_separator);
        }
        writing_to_file_line = writing_to_file_line.substr(writing_to_file_line.size()-1);
        file << writing_to_file_line << endl;
    }
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
            line_to_write_here.append(*it + basic_csv_separator);
        }
        line_to_write_here.substr(line_to_write_here.size()-1);
        file << line_to_write_here << endl;

        //second line is writing boolean restrictions into file.
        string line2; 
        for (list<bool>::const_iterator it = user_data.food_and_dietary_restrictions.begin(); it != user_data.food_and_dietary_restrictions.end(); it++) {
            line2.append(to_string(*it) + basic_csv_separator); //outputs "0" or "1" in string repr.
        }
        line2 = line2.substr(line2.size()-1);
        file << line2 << endl;
    }
}

void write_offer_list() {
    ofstream file;
    file.open(Database_fridge_and_food_lists_data);
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
            line_to_write_string.append(*it + basic_csv_separator);
        }
        line_to_write_string = line_to_write_string.substr(line_to_write_string.size()-1);
        file << line_to_write_string << endl;
    }
}


void write_to_csv() {
    write_simple_types();
    write_fridge_and_food_lists();
    write_offer_list();
}



void read_from_csv_old() { //everytime open the server, read csv to get data from previous session
//    ifstream file;
//    file.open(Database_fridge_and_food_lists_data);
//    vector<string> lines;
//    for (string line; getline(file, line);) {
//        lines.push_back(line);
//    }
//    cout << "Here we are";
//    for (auto line : lines) {
//        //separate the lines into username, data format. Use csv_separator designed to avoid conflicts with client-side. i.e. people naming their fruits "apple,ornot}[%" and this messing up my whole process.
//        stringstream s_line(line);

//        vector<string> user_data_from_line;
//        for (string item; getline(s_line, item, basic_csv_separator);) {
//            user_data_from_line.push_back(item);
//        }
//        //user_data_from_line looks like : [username, telegram_username, password, fridge, offer_list] afterwards. All strings.
//        //convert fridge string "{[name: category: quantity: expiry_date: priority_level]; [...]; ...}" or an empty fridge string.
//        vector<vector<string>> fridge_vec;
//        if (!(user_data_from_line[3] == curly_brackets_sep)) { //nonempty fridge, run stuff with it.

//            stringstream s_fridge(user_data_from_line[3].substr(1, size(user_data_from_line[3]) -2)); //fridge, with {curly brackets} removed.
//            for (string ingr_str; getline(s_fridge, ingr_str, ingr_separator_in_fridge);) { //separate into ingredients = "[name:category:qty:exp_date:prior]"
//                vector<string> ingr;
//                stringstream ingr_stream(ingr_str.substr(1, size(ingr_str) -2));
//                for (string ingr_element; getline(ingr_stream, ingr_element, separator_within_ingredient);) {
//                    ingr.push_back(ingr_element);
//                }
//                fridge_vec.push_back(ingr);
//            }
//        }


//        //convert offer_list string "|{[name: category: quantity: expiry_date: priority_level]; [...]; ...; [price]}/{...}/...|" or an empty offer_list.
//        vector<vector<vector<vector<string>>>> offer_list_vec;
//        if (!(user_data_from_line[4] == absolute_signs_sep)) {
//            stringstream s_offers(user_data_from_line[4].substr(1, size(user_data_from_line[4]) - 2));
//            for (string offer_str; getline(s_offers, offer_str, separator_within_offer_list);) {
//                vector<vector<vector<string>>> offer;
//                stringstream s_offer(offer_str.substr(1, size(offer_str) -2));
//                vector<vector<string>> ingredient_vector;
//                vector<vector<string>> price_vector;
//                for (string ingredient_or_price_str; getline(s_offer, ingredient_or_price_str, ingr_separator_in_fridge);) {
//                    //now, reduce the ingredients to vector<string>, and consider the price separately.
//                    vector<string> ingr_or_price;
//                    stringstream ingr_price_stream(ingredient_or_price_str.substr(1, size(ingredient_or_price_str) -2));
//                    for (string ingr_price_element; getline(ingr_price_stream, ingr_price_element, separator_within_ingredient);) {
//                        ingr_or_price.push_back(ingr_price_element);
//                    }

//                    if (size(ingr_or_price) == 5) { //then we have an ingredient, the price contains 1 elements.
//                        ingredient_vector.push_back(ingr_or_price);
//                    }
//                    else {
//                        price_vector.push_back(ingr_or_price);
//                    }
//                }
//                offer.push_back(ingredient_vector);
//                offer.push_back(price_vector);
//                offer_list_vec.push_back(offer);
//            }
//        }

//        //append username and data to db:
//        UserData data;
//        data.password = user_data_from_line[2];
//        data.telegram_username = user_data_from_line[1];
//        data.fridge = fridge_vec;
//        data.offer_list = offer_list_vec;
//        (*database)[user_data_from_line[0]] = data;
//    }
//    file.close();
}

void save_to_csv_old() { //save data of the map in a csv
//    ofstream file(Database_fridge_and_food_lists_data);

//    //generate a vector of the lines to write. Then, write the lines, using: file << string << endl;
//    vector<string> lines;
//    for (auto& [u_name, u_data]: *(database)) {        
//        string line = u_name + basic_csv_separator + u_data.telegram_username + basic_csv_separator + u_data.password + basic_csv_separator;

//        //then, unpack a fridge into the format: "{[name: category: quantity: expiry_date: priority_level]; [...]; ...}" exactly, modulo any spacebars.
//        string f_string = "";
//        int numLeft = size(u_data.fridge);
//        if (!(numLeft == 0)) { //empty fridge, "{}" instead.
//            for (vector<vector<string>>::iterator ingredient = u_data.fridge.begin(); ingredient != u_data.fridge.end(); ++ingredient) {
//                numLeft --;
//                string ingr_str = "";
//                int count=0;
//                for (vector<string>::iterator ingr_element = ingredient->begin(); ingr_element != ingredient->end(); ++ingr_element) {
//                    count += 1;
//                    if (count == 5) {
//                        ingr_str += *ingr_element;
//                    }
//                    else {
//                        ingr_str += *ingr_element + separator_within_ingredient;
//                    }
//                }
//                ingr_str = square_brackets_sep[0] + ingr_str + square_brackets_sep[1];

//                //concatenate ingredients into fridge string.
//                if (numLeft == 0) {
//                    f_string += ingr_str;
//                }
//                else {
//                    f_string += ingr_str + ingr_separator_in_fridge;
//                }
//            }
//        }
//        f_string = curly_brackets_sep[0] + f_string + curly_brackets_sep[1];
//        line += f_string + basic_csv_separator;

//        //deal with offer list now: convert to "⊂≺⊏name: category: quantity: expiry_date: priority_level⊐; ⊏...⊐; ...; ⊏price⊐≻/≺...≻/...⊃", from vecx4 <string>
//        string o_l_string = "";
//        numLeft = size(u_data.offer_list); //repurpose numLeft for this iteration.
//        if (!(numLeft == 0)) {//so that empty offer_list = "||"
//            for (vector<vector<vector<vector<string>>>>::iterator offer = u_data.offer_list.begin(); offer != u_data.offer_list.end(); ++offer) {
//                string price = (*offer)[1][0][0]; //offer[1] is price in a vector<vector<string>>
//                price = square_brackets_sep[0] + price + square_brackets_sep[1];

//                //repack ingredient list into string, just like in a fridge:
//                //offer[0] is a vector<vector<string>>, of ingredients.
//                string ingr_list;
//                for (vector<vector<string>>::iterator ingredient = (*offer)[0].begin(); ingredient != (*offer)[0].end(); ++ingredient) {
//                    string ingr_str = "";
//                    int count=0;
//                    for (vector<string>::iterator ingr_element = ingredient->begin(); ingr_element != ingredient->end(); ++ingr_element) {
//                        count += 1;
//                        if (count == 5) {
//                            ingr_str += *ingr_element;
//                        }
//                        else {
//                            ingr_str += *ingr_element + separator_within_ingredient;
//                        }
//                    }
//                    ingr_str = square_brackets_sep[0] + ingr_str + square_brackets_sep[1];

//                    ingr_list += ingr_str + ingr_separator_in_fridge;
//                }

//                //concatenate offers into offer list string.
//                string o_string = ingr_list + price;
//                o_string = curly_brackets_sep[0] + o_string +  curly_brackets_sep[1];
//                numLeft --;
//                if (numLeft == 0) {
//                    o_l_string += o_string;
//                }
//                else {
//                    o_l_string += o_string + separator_within_offer_list;
//                }
//            }
//        }

//        o_l_string = absolute_signs_sep[0] + o_l_string + absolute_signs_sep[1];
//        line += o_l_string;
//        //now, pushback line into line list
//        lines.push_back(line);
//    }
//    //then, write lines into file.
//    for (vector<string>::iterator line_it = lines.begin(); line_it != lines.end(); ++line_it) {
//        //        cout << "Writing line " << *(line_it) <<endl; //for debug purposes.
//        file << *(line_it) << endl;
//    }
//    file.close();
}


void init_data_test() { //debug function. Tests database read/write all together along with test_read_write_csv().
    UserData data;
    data.password = "Darton";
    vector<vector<string>> fridge_darton;
    vector<string> apple;
    string name = "apple", category = "cat1", qty="3", exp_date = "22.10.2024", priority_level = "RED";
    apple.push_back(name); apple.push_back(category); apple.push_back(qty); apple.push_back(exp_date); apple.push_back(priority_level);
    fridge_darton.push_back(apple); fridge_darton.push_back(apple);
    data.fridge = fridge_darton;
    string m = "Molly";
    (*database)[m] = data;
    string k = "Johnny";
    vector<vector<string>> offer;
    offer.push_back(data.fridge[0]);
    string price_str = "10";
    vector<string> price;
    price.push_back(price_str);
    offer.push_back(price);
    data.offer_list.push_back(offer); data.offer_list.push_back(offer);
    (*database)[k] = data;
}

int test_read_write_csv() {
    init_data_test();
    write_to_csv();
    read_from_csv();
    cout <<"Feel free to check database.csv! You will gleefully see new items added :)";
    database; //open this while in debug mode to test, from qt it will give nice informations.
    return 0;
}

int val = test_read_write_csv();


//.////Real Server Stuff:

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
    
void update_user_characteristics(string username, string password, basic_user_data new_characs) {
    auto el = database->find(username);
    
    if (el != database->end() && password==el->second.password) {
            el->second.display_name = new_characs.display_name;
            el->second.telegram_username = new_characs.telegram_username;
            el->second.gender = new_characs.gender;
            el->second.promotion = new_characs.promotion;
            el->second.building_address = new_characs.building_address;
            el->second.phone_number = new_characs.phone_number;
            el->second.food_and_dietary_restrictions = new_characs.food_and_dietary_restrictions;
            el->second.telegram_notifications = new_characs.telegram_notifications;
            el->second.marketplace_notifications = new_characs.marketplace_notifications;
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

void update_fridge(std::string username, string password, vector<vector<string>> &new_fridge) {
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

void update_offer(std::string username, string password, vector<vector<vector<string>>> &new_offer) {
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

//DB Sending Functions:
vector<vector<vector<string>>> get_offer_list(string username, string password) {
        auto el = database->find(username); // Find the username in the database

        if (el != database->end() && password == el->second.password) {
            // Username exists and password matches

            // Move the offer_list content to the caller
            return std::move(el->second.offer_list);
        }


        return {}; // Return an empty offer_list if no username or password does not match

}
vector<vector<string>> get_fridge(string username, string password) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end() && password == el->second.password) {
            // Username exists and password matches


            return std::move(el->second.fridge);
        }


        return {}; // Return an empty offer_list if no username or password does not match

}

vector<string> get_user_name_vectors() {
        vector<string> user_list;
        for (auto& [key, value] : *database) {
            user_list.push_back(key);
        }
        return user_list;
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
void test_sending_fridges(vector_of_ingredients fridge) {
    cout << fridge[0].name << fridge[0].quantity << endl;
}

void test_sending_fridges_vector_edition(vector<string> fridge) {
    cout << fridge[0][0] << fridge[0][1] << endl;
}




int main() {
    rpc::server srv(HOST_SERVER_PORT);
    
    
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
    srv.bind("get_user_name_vectors", &get_user_name_vectors);
    
    //Check functions:
    srv.bind("check_user", &check_user);
    
    //test read-write of database here:
//    cout << "Started";
//    int test1 = test_read_write_csv();
//    cout << "Done";
    
    cout << "running";
    
    //binding test functions:
    srv.bind("test_sending_fridges", &test_sending_fridges);
    srv.bind("test_sending_fridges_vector_edition", &test_sending_fridges_vector_edition);
    
    
    //SERVER running from here: 
    srv.run();
    
    
//    read_from_csv(); Uncomment when actual testing server begins.    
    
    
//    write_to_csv();  Same-same. Uncomment when testing begins.
    return 0;    
}
