#include <iostream>
#include <string>
#include<vector>
#include <sstream>
#include "rpc/client.h"
<<<<<<< HEAD:server/POCOSocket/Server/rpc_client_side.cpp
#include "rpc_client_side.hpp"
#include "front.hpp"
#include "ingredient.h"
#include "date.h"
#include "fridge.h"
#include "offer.h"
#include "user.h"
#include "rpc/server.h"

=======
#include "rpc_client_side_tester_file.hpp"
>>>>>>> 659436767f92c208cbdd5994e12e21d2a20e2b5e:server/POCOSocket/Server/rpc_client_side_tester_file.cpp



//for banned-character-error: TAB, ~, *, >, {, }, [, ], | <- these are all the banned characters.


using namespace std;

string HOST_SERVER_NAME = "127.0.0.1"; //change to Server later.
int HOST_SERVER_PORT = 3333;


//.//////New Types for data transfer:
struct offer_list_vector {
    vector<vector<vector<string>>> offer_list;
    MSGPACK_DEFINE_ARRAY(offer_list)
};

struct fridge_vector {
    vector<vector<string>> fridge_vector;
    MSGPACK_DEFINE_ARRAY(fridge_vector)
};

struct vector_list{
    vector<string> vec;
    MSGPACK_DEFINE_ARRAY(vec)   //to use in function get_user_list;
};

struct basic_user_data {
    string display_name;
    string telegram_username;
    int gender;
    int promotion;
    string building_address;
    int phone_number;
    list<bool> food_and_dietary_restrictions;
    int telegram_notifications;
    int marketplace_notifications;
    MSGPACK_DEFINE_ARRAY(display_name, telegram_username, gender, promotion, building_address, phone_number, food_and_dietary_restrictions, telegram_notifications, marketplace_notifications)
};


//.///////// User functions

ServerUser::ServerUser(string usrname, string psswd) { //Add user to db if user not in db already. Oth, just initialise connection.
    username = usrname;
    password = psswd;
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("add_user", username, password);
}

ServerUser::~ServerUser() {}

void ServerUser::delete_self_in_db() {
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("remove_user", username, password);
}

void ServerUser::update_user_characteristics(User usr) {
    basic_user_data basic_data;
    basic_data.display_name = usr.get_display_name();
    basic_data.telegram_username = usr.get_telegram_username();
    basic_data.gender = usr.get_gender();
    basic_data.promotion = usr.get_promotion();
    basic_data.building_address = usr.get_building_address();
    basic_data.phone_number = usr.get_phone_number();
    basic_data.food_and_dietary_restrictions = usr.get_food_and_dietary_restrictions();
    basic_data.telegram_notifications = usr.get_telegram_notifications();
    basic_data.marketplace_notifications = usr.get_marketplace_notifications();
    
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_user_characteristics", username, password, basic_data);
}

//////////General Functions:

vector<string> get_user_name_list() {
    rpc::client new_client(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_client.call("get_user_name_list").as<vector_list>();
}


//.///////// Mapping Types

Food_class mapCategoryToEnum(const std::string& category) {
    static const std::unordered_map<std::string, Food_class> categoryMap = {
        {"fruit", fruit},
        {"vegetable", vegetable},
        {"drink", drink},
        {"dairy", dairy},
        {"canned", canned},
        {"meat", meat},
        {"fish", fish},
        {"sweet", sweet},
        {"nut", nut},
        {"unspecified", unspecified},
        {"other", other}
    };

    auto it = categoryMap.find(category);
    if (it != categoryMap.end()) {
        return it->second;
    } else {
        return unspecified;
    }
}

Priority mapprioToEnum(const std::string& priority_level) {
    static const std::unordered_map<std::string, Priority> PrioMap = {
        {"red", red},
        {"orange",orange},
        {"green",green}
    };

    auto it = PrioMap.find(priority_level);
    if (it != PrioMap.end()) {
        return it->second;
    }
}


std::string_view foodClassToString(Food_class foodClass) {
    static const std::unordered_map<Food_class, std::string_view> FoodClassToString = {
        {Food_class::fruit, "fruit"},
        {Food_class::vegetable, "vegetable"},
        {Food_class::drink, "drink"},
        {Food_class::dairy, "dairy"},
        {Food_class::canned, "canned"},
        {Food_class::meat, "meat"},
        {Food_class::fish, "fish"},
        {Food_class::sweet, "sweet"},
        {Food_class::nut, "nut"},
        {Food_class::unspecified, "unspecified"},
        {Food_class::other, "other"}
    };

    auto it = FoodClassToString.find(foodClass);
    if (it != FoodClassToString.end()) {
        return it->second;
    } else {
        return "Unknown";
    }
}



std::string priorityToString(Priority priority) {
    static const std::unordered_map<Priority, std::string> PriorityToString = {
        {Priority::red, "red"},
        {Priority::orange, "orange"},
        {Priority::green, "green"}
    };

    auto it = PriorityToString.find(priority);
    if (it != PriorityToString.end()) {
        return it->second;
    } else {
        return "Unknown"; // Return a default string for unknown values
    }
}


//OSCAR's CODE: to adjust and change if u have a way which matches smth u prefer to use.

//THIS WORKS !!
vector<string> ingredient_to_vector(Ingredient &ingr) { //returns vector as [name, expiry_date, quantity, category, priority_level], all as string s. I modified the format Adam
    vector<string> vec;

    // first push name
    vec.push_back(ingr.get_name());

    // then  push expiry_date

    vec.push_back(to_string(ingr.get_expiry_date().get_day()) +"."+to_string(ingr.get_expiry_date().get_month())+ "." + to_string(ingr.get_expiry_date().get_year())); // date --> 22.10.2024 --> string


    // push quantity
    vec.push_back(to_string(ingr.get_quantity()));


    // push category

    string cat_string(foodClassToString(ingr.get_food_class())); // Convert std::string_view to std::string
    vec.push_back(cat_string);

    // push priority_level

    string priority_string(priorityToString(ingr.get_priority()));
    vec.push_back(priority_string);

    return vec;
}



Ingredient ingredient_from_vector(std::vector<std::string> vector) { //Oscar work yo magic
 // Convert string name into --> string name --> nothing to change
    std::string name = vector[0];

    // Convert date expiry_date --> string --> nothing to change

    std::istringstream ss(vector[1]);
    std::vector<int> intArray;
    std::string token;

    while (std::getline(ss, token, '.')) {
        intArray.push_back(std::stoi(token));
    }

    Date expiry_date = Date(intArray[0], intArray[1], intArray[2]);


    // Convert string quantity into --> int quantity :
    int quantity = std::stoi(vector[2]);

    // Convert string category into --> in food class enum

    Food_class category = mapCategoryToEnum(vector[3]);



    // Convert priority level string into --> enum

    Priority priority_level = mapprioToEnum(vector[4]);

    // Ingredient::Ingredient(string name, Date expiry_date, int quantity, Food_class category){
    Ingredient ingredient = Ingredient(name,expiry_date, quantity, category);
    ingredient.set_priority(priority_level);
    return ingredient;
}




//ayo Es^ these are the interesting ideas I started to explore from rpclib.com, find out if this works or not, and find a better method if it exists othw. rpclib.com will have all necessary info, hopefully

//Excluding characters

//LIST of chars to exclude: TAB, ~, *, >, {, }, [, ], |
char char_exclude_list[9] = {(char)9, *"~", *"*", *">", *"{", *"}", *"[", *"]", *"|"};
bool char_to_exclude_satisfied(string input_string) {
    for (int i=0; i <sizeof(char_exclude_list); i++) { //iterate through exclusion list, check find, if returned string::npos; return false.
        size_t found_or_not = input_string.find(char_exclude_list[i]);
        if (found_or_not != string::npos) {
            cout << "Character Matched!" << endl;
            return false;
        }
    }
    cout << "All good, no match!" << endl;
    return true;
}



//#/// Server send-receive functions.

Fridge ServerUser::get_fridge() { //
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    fridge_vector fridge_vector1 = new_cli.call("get_fridge", username, password).as<fridge_vector>(); //vector of ingredients, each as a vector of strings.
    //Oscar work yo magic
    //     Fridge(std::list<Ingredient> init_list);
    std::vector<Ingredient> vector_Ingredient;

    for (size_t i = 0; i < fridge_vector1.fridge_vector.size(); ++i) {

        vector<string> ingredient = fridge_vector1.fridge_vector[i];
        vector_Ingredient.push_back(ingredient_from_vector(ingredient));
    }

    return Fridge(vector_Ingredient);
}



void ServerUser:: update_fridge(Fridge &f_input) {
    //convert to database-wanted format: OSCAR'S METHOD
    vector<vector<string>> fridge;


    vector<Ingredient> ingredient_list = f_input.get_list();

    for (size_t i = 0; i < ingredient_list.size(); ++i){
        // Convert each Ingredient to vector format using Oscar's code
        vector<string> ingredient = ingredient_to_vector(ingredient_list[i]);  // Pass the current Ingredient object
        //check the vector contains only allowed characters:
        for (vector<string>::iterator it= ingredient.begin(); it != ingredient.end(); it++) {
            if (char_to_exclude_satisfied(*it) == false) {cout << "ValueError: ingredient contains disallowed characters. See top of client_side for list.";return;}
        }


        // Push the converted ingredient into the fridge vector
        fridge.push_back(ingredient);
    }

    /*
    for (list<Ingredient>::iterator i = f_input.ingredient_list.begin(); i != f_input.ingredient_list.end(); i++) {

        //convert ingredient to vector format USING OSCAR's CODE
        vector<string> ingredient;
        fridge.push_back(ingredient_to_vector(ingredient));
    }
    */

    //send as new format
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_fridge", username, password, fridge);
}



// To re-do !!



vector<Offer> ServerUser::get_offer_list() {  //  [[Ingredient_vector1, [PRICE1]], [Ingredient_vector2, [PRICE2]], ... ,]
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    //vector<vector<vector<vector<string>>>> offer_list_vector = new_cli.call("get_offer_list", username, password);
    offer_list_vector offer_list_vector1 = new_cli.call("get_fridge", username, password).as<offer_list_vector>();
    //Oscar work yo magic: ADDED DETAIL: The offer list format holds offers, each other has this format exactly: [vector<vector<string>>, vector<vector<string>>], Where the second vector stores only a double!
    //That double represents the price of the offer. We needed this because vectors have homogenous type. (only store one type.)

    //    double doubleValue = std::stod(numericalString);
    std::vector<Offer> vector_offer;

    for (size_t i = 0; i < offer_list_vector1.offer_list.size(); ++i) {
        Offer offer_i;
        offer_i.set_ingredient(ingredient_from_vector(offer_list_vector1.offer_list[i][0]));
        double price = std::stod(offer_list_vector1.offer_list[i][1][0]);
        offer_i.set_price(price);
        vector_offer.push_back(offer_i);
    }
    return vector_offer;
}


void ServerUser::update_offer_list(vector<Offer> &offer_list) {
    //Oscar work yo magiiiic: same format as get_offer_list for the data we want to give to the server.
    // vector<Offer> --> [[Ingredient_vector1, [PRICE1]], [Ingredient_vector2, [PRICE2]], ... ,]

    vector<vector<vector<string>>> update_offer;
    for (size_t j = 0; j < offer_list.size(); ++j){
        Offer offer_elem =  offer_list[j];

        // deal with price
        double price = offer_elem.get_price();
        string string_price = to_string(price);

        vector<string> price_vector;

        price_vector.push_back(string_price);


        // deal with Ingredient
        Ingredient ingredient_offer = offer_elem.get_ingredient();


        vector<string> ingredient_vector = ingredient_to_vector(ingredient_offer);

        // for CSV file !
        for (vector<string>::iterator it= ingredient_vector.begin(); it != ingredient_vector.end(); it++) {
            if (char_to_exclude_satisfied(*it) == false) {cout << "ValueError: ingredient contains disallowed characters. See top of client_side for list.";return;}
        }
<<<<<<< HEAD:server/POCOSocket/Server/rpc_client_side.cpp
        vector<vector<vector<string>>> list_ingr_price;
        list_ingr_price.push_back(update_list_ingredient);
        vector<vector<string>> price_element ;
        vector<string> inner_vector;
        inner_vector.push_back(string_price);
        price_element.push_back(inner_vector);
        // adding the [[price]] to the array with the list ingredients
        list_ingr_price.push_back(price_element);
        update_offer.push_back(list_ingr_price);
    }


    
=======
        vector<vector<string>> ingredient_price;

        ingredient_price.push_back(ingredient_vector);
        ingredient_price.push_back(price_vector);

            //check broken characters: if banned or not

        update_offer.push_back(ingredient_price);
        }


    // make sure the format works !!

>>>>>>> 659436767f92c208cbdd5994e12e21d2a20e2b5e:server/POCOSocket/Server/rpc_client_side_tester_file.cpp
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_offer_list", username, password, update_offer);

}


<<<<<<< HEAD:server/POCOSocket/Server/rpc_client_side.cpp
std::unordered_map<std::string, std::vector<std::vector<std::vector<std::vector<std::string>>>>>
get_all_clients_with_offers() {
    rpc::client cl(HOST_SERVER_NAME, HOST_SERVER_PORT);

    // Perform an RPC call to the server to retrieve all clients with their offers
    auto clientsWithOffers = cl.call("getMapOfOffers").as<
        std::unordered_map<std::string, std::vector<std::vector<std::vector<std::vector<std::string>>>>>
        >();

    return clientsWithOffers;
}
=======
int test_msgpack(){


>>>>>>> 659436767f92c208cbdd5994e12e21d2a20e2b5e:server/POCOSocket/Server/rpc_client_side_tester_file.cpp


    /*
    vector<vector<vector<string>>> ex_offer_list;

    vector<vector<string>> ingredient_price ;

    vector<string> ingredient;

    vector<string> price;



    vector<string> ingredient.push_back("apple");
    vector<string> ingredient.push_back("11.11.2005");
    vector<string> ingredient.push_back("25kg");
    vector<string> ingredient.push_back("meat");
    vector<string> ingredient.push_back("red");

    vector<string> price.push_back("11$");

    ingredient_price.push_back(ingredient);
    ingredient_price.push_back(price);
    ex_offer_list.push_back(ingredient_price);
    */

    Offer offer;
    offer.set_ingredient(Ingredient("apple", Date(24,6,2004) , 1, drink));
    offer.set_price(1.5);
    vector<Offer> offer_vector;
    offer_vector.push_back(offer);

    ServerUser srv1_usr("oscar", "123");

    srv1_usr.update_offer_list(offer_vector);



return 1;


    // [name, expiry_date, quantity, category, priority_level]


}



int var = test_msgpack();

