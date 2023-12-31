#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "rpc/server.h"
#include "rpc/client.h"
#include "rpc/this_session.h"
#include "rpc/this_handler.h"

using namespace std;
const string DATABASE_CSV_FILE = "../Server/database.csv";
//FILE FORMATS:

//Ingredients: vector<string>>
//Fridge: vector<vector<string>>
//Offer: vector<vector<vector<string>>>: with vectors represented as {}, an offer looks like: { {Ingredient1, Ingredient2, etc}, {{price}} } where all elements are strings.
//Offer List: vector<vector<vector<vector<string>>>>, looking like {Offer1, Offer2, etc}.
//Database: unordered_map<string, UserData>, dicts as [], looking like  [username1: UserData, username2: UserData], with UserData having:

class UserData {
public:
    UserData(string password){
        this->password = password;
    };
    string password;
    vector<vector<string>> fridge;
    vector<vector<vector<vector<string>>>> offer_list;
};

unordered_map<string, UserData>* database = new unordered_map<string, UserData>;

//silly needs for delimiter type within getline():
char comma = *",";
char semicolon = *";";
char colon = *":";
char forwardslash = *"/";

//needs for string comparison (why, c++)
string curly_brackets = "{}";
string absolute_signs = "||";


//Storage format: username, password, fridge, offer;
//Inspired from iq.opengenus.org/read-and-write-in-csv-cpp/
void read_from_csv() { //everytime open the server, read csv to get data from previous session
    ifstream file;
    file.open(DATABASE_CSV_FILE);
    vector<string> lines;
    for (string line; getline(file, line);) {
        lines.push_back(line);
    }
    cout << "Here we are";
    for (auto line : lines) {
        //comma-separate the lines into username, data format.
        stringstream s_line(line);

        vector<string> user_data_from_line;
        for (string item; getline(s_line, item, comma);) {
            user_data_from_line.push_back(item);
        }
        //user_data_from_line looks like : [username, password, fridge, offer_list] afterwards. All strings.
        //convert fridge string "{[name: category: quantity: expiry_date: priority_level]; [...]; ...}" or "{}" for empty fridge.
        vector<vector<string>> fridge_vec;
        if (!(user_data_from_line[2] == curly_brackets)) { //nonempty fridge, run stuff with it.

            stringstream s_fridge(user_data_from_line[2].substr(1, size(user_data_from_line[2]) -2)); //fridge, with {curly brackets} removed.
            for (string ingr_str; getline(s_fridge, ingr_str, semicolon);) { //separate into ingredients = "[name:category:qty:exp_date:prior]"
                vector<string> ingr;
                stringstream ingr_stream(ingr_str.substr(1, size(ingr_str) -2));
                for (string ingr_element; getline(ingr_stream, ingr_element, colon);) {
                    ingr.push_back(ingr_element);
                }
                fridge_vec.push_back(ingr);
            }
        }


        //convert offer_list string "|{[name: category: quantity: expiry_date: priority_level]; [...]; ...; [price]}/{...}/...|" or "||" empty offer_list.
        vector<vector<vector<vector<string>>>> offer_list_vec;
        if (!(user_data_from_line[3] == absolute_signs)) {
            stringstream s_offers(user_data_from_line[3].substr(1, size(user_data_from_line[3]) - 2));
            for (string offer_str; getline(s_offers, offer_str, forwardslash);) {
                vector<vector<vector<string>>> offer;
                stringstream s_offer(offer_str.substr(1, size(offer_str) -2));
                vector<vector<string>> ingredient_vector;
                vector<vector<string>> price_vector;
                for (string ingredient_or_price_str; getline(s_offer, ingredient_or_price_str, semicolon);) {
                    //now, reduce the ingredients to vector<string>, and consider the price separately.
                    vector<string> ingr_or_price;
                    stringstream ingr_price_stream(ingredient_or_price_str.substr(1, size(ingredient_or_price_str) -2));
                    for (string ingr_price_element; getline(ingr_price_stream, ingr_price_element, colon);) {
                        ingr_or_price.push_back(ingr_price_element);
                    }

                    if (size(ingr_or_price) == 5) { //then we have an ingredient, the price contains 1 elements.
                        ingredient_vector.push_back(ingr_or_price);
                    }
                    else {
                        price_vector.push_back(ingr_or_price);
                    }
                }
                offer.push_back(ingredient_vector);
                offer.push_back(price_vector);
                offer_list_vec.push_back(offer);
            }
        }

        //append username and data to db:
        UserData data;
        data.password = user_data_from_line[1];
        data.fridge = fridge_vec;
        data.offer_list = offer_list_vec;
        (*database)[user_data_from_line[0]] = data;
    }
    file.close();
}

void save_to_csv() { //save data of the map in a csv
    ofstream file(DATABASE_CSV_FILE);

    //generate a vector of the lines to write. Then, write the lines, using: file << string << endl;
    vector<string> lines;
    for (auto& [u_name, u_data]: *(database)) {
        //first, unpack username and password.
        string line = u_name + "," + u_data.password + ",";

        //then, unpack a fridge into the format: "{[name: category: quantity: expiry_date: priority_level]; [...]; ...}" exactly, modulo any spacebars.
        string f_string = "";
        int numLeft = size(u_data.fridge);
        if (!(numLeft == 0)) { //so that empty fridge = "{}".
            for (vector<vector<string>>::iterator ingredient = u_data.fridge.begin(); ingredient != u_data.fridge.end(); ++ingredient) {
                numLeft --;
                string ingr_str = "";
                int count=0;
                for (vector<string>::iterator ingr_element = ingredient->begin(); ingr_element != ingredient->end(); ++ingr_element) {
                    count += 1;
                    if (count == 5) {
                        ingr_str += *ingr_element;
                    }
                    else {
                        ingr_str += *ingr_element + ":";
                    }
                }
                ingr_str = "[" + ingr_str + "]";

                //concatenate ingredients into fridge string.
                if (numLeft == 0) {
                    f_string += ingr_str;
                }
                else {
                    f_string += ingr_str + ";";
                }
            }
        }
        f_string = "{" + f_string + "}";
        line += f_string + ",";

        //deal with offer list now: convert to "|{[name: category: quantity: expiry_date: priority_level]; [...]; ...; [price]}/{...}/...|", from vecx4 <string>
        string o_l_string = "";
        numLeft = size(u_data.offer_list); //repurpose numLeft for this iteration.
        if (!(numLeft == 0)) {//so that empty offer_list = "||"
            for (vector<vector<vector<vector<string>>>>::iterator offer = u_data.offer_list.begin(); offer != u_data.offer_list.end(); ++offer) {
                string price = (*offer)[1][0][0]; //offer[1] is price in a vector<vector<string>>
                price = "[" + price + "]";

                //repack ingredient list into string, just like in a fridge:
                //offer[0] is a vector<vector<string>>, of ingredients.
                string ingr_list;
                for (vector<vector<string>>::iterator ingredient = (*offer)[0].begin(); ingredient != (*offer)[0].end(); ++ingredient) {
                    string ingr_str = "";
                    int count=0;
                    for (vector<string>::iterator ingr_element = ingredient->begin(); ingr_element != ingredient->end(); ++ingr_element) {
                        count += 1;
                        if (count == 5) {
                            ingr_str += *ingr_element;
                        }
                        else {
                            ingr_str += *ingr_element + ":";
                        }
                    }
                    ingr_str = "[" + ingr_str + "]";

                    ingr_list += ingr_str + ";";
                }

                //concatenate offers into offer list string.
                string o_string = ingr_list + price;
                o_string = "{" + o_string +  "}";
                numLeft --;
                if (numLeft == 0) {
                    o_l_string += o_string;
                }
                else {
                    o_l_string += o_string + "/";
                }
            }
        }

        o_l_string = "|" + o_l_string + "|";
        line += o_l_string;
        //now, pushback line into line list
        lines.push_back(line);
    }
    //then, write lines into file.
    for (vector<string>::iterator line_it = lines.begin(); line_it != lines.end(); ++line_it) {
        //        cout << "Writing line " << *(line_it) <<endl; //for debug purposes.
        file << *(line_it) << endl;
    }
    file.close();
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
    vector<vector<vector<string>>> offer;
    offer.push_back(data.fridge);
    string price_str = "10";
    vector<string> inner_price;
    vector<vector<string>> price;
    inner_price.push_back(price_str);
    price.push_back(inner_price);
    offer.push_back(price);
    data.offer_list.push_back(offer); data.offer_list.push_back(offer);
    (*database)[k] = data;
}

int test_read_write_csv() {
    init_data_test();
    save_to_csv();
    read_from_csv();
    cout <<"Feel free to check database.csv! You will gleefully see new items added :)";
    return 0;
}

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
        }
    } else {
        // Username not found
    }

}
void update_user(string old_username, string old_password, string new_username, string new_password) {
    auto el = database->find(old_username); // Find the username in the database
    if (el != database->end()) {
        // Username exists
        if (old_password == el->second.password) {
            // Password matches
            UserData data = el->second;
            database->erase(el);
            add_user(new_username, new_password);
            }
        }
    }//changes a user's name and password. Old is for login verification, new is to change.

void update_fridge(std::string username, string password, vector<vector<string>> new_fridge) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
                // Password matches
            el->second.fridge = new_fridge;
            }
        }
} //updates a user fridge

void update_offer(std::string username, string password, vector<vector<vector<vector<string>>>> new_offer) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
            // Password matches
            el->second.offer_list = new_offer;
            }
        }
} //updates a user offer list

//DB Sending Functions:
vector<vector<vector<vector<string>>>> get_offer_list(string username, string password) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
            // Password matches
            return el->second.offer_list;
            }
        }
}
vector<vector<string>> get_fridge(string username, string password) {
        auto el = database->find(username); // Find the username in the database
        if (el != database->end()) {
            // Username exists
            if (password == el->second.password) {
            // Password matches
            return el->second.fridge;
            }
        }
}

int main() {
    rpc::server srv(3333);
    
    //DB Manip
    srv.bind("add_user", &add_user);
    srv.bind("remove_user", &remove_user);
    srv.bind("update_user", &update_user);
    
    srv.bind("update_fridge", &update_fridge);
    srv.bind("update_offer", &update_offer);
    
    //DB Sending
    srv.bind("get_fridge", &get_fridge);
    srv.bind("get_offer_list", &get_offer_list);
    

    // template for error messages ::we keep this or not? To William, from Adam
    srv.bind("error", []() {
        auto err_obj = std::make_tuple(13, "Errors are arbitrary objects");
        rpc::this_handler().respond_error(err_obj);
    });

        
    srv.run();
    return 0;
}
