#include <iostream>
#include <string>
#include<vector>

#include "rpc/client.h"
#include "rpc_client_side_tester_file.hpp"


using namespace std;


//          User Updating and creating functions.

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
//    basic_data.food_and_dietary_restrictions = usr.get_food_and_dietary_restrictions();
    basic_data.telegram_notifications = usr.get_telegram_notifications();
    basic_data.marketplace_notifications = usr.get_marketplace_notifications();
    
    //    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    //    new_cli.call("update_user_characteristics", username, password, basic_data);
}

//      General Functions:

vector<string> get_user_name_list() {
    rpc::client new_client(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_client.call("get_user_name_vectors");
}


//          Type Mapping,  

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



vector<string> ingredient_to_vector(Ingredient &ingr) { //returns vector as [name, expiry_date, quantity, category, priority_level], all as string s. I modified the format Adam
    vector<string> vec;
    
    vec.push_back(ingr.get_name()); //first name, then the rest, in order listed above.
    
    vec.push_back(to_string(ingr.get_expiry_date().get_day()) +"."+to_string(ingr.get_expiry_date().get_month())+ "." + to_string(ingr.get_expiry_date().get_year())); // date --> 22.10.2024
    
    vec.push_back(to_string(ingr.get_quantity()));
    
    
    string cat_string(foodClassToString(ingr.get_food_class())); // Convert std::string_view to std::string
    vec.push_back(cat_string);
    
    string priority_string(priorityToString(ingr.get_priority()));
    vec.push_back(priority_string);
    
    return vec;
}



Ingredient ingredient_from_vector(std::vector<std::string> vector) { //Oscar work yo magic
    // Convert string name 
    std::string name = vector[0];
    
    // Convert date expiry
    
    std::istringstream ss(vector[1]);
    std::vector<int> intArray;
    std::string token;
    
    while (std::getline(ss, token, '.')) {
        intArray.push_back(std::stoi(token));
    }
    
    Date expiry_date = Date(intArray[0], intArray[1], intArray[2]);
    
    
    // Convert string quantity into int
    int quantity = std::stoi(vector[2]);
    
    // Convert string category into food_class enum.
    
    Food_class category = mapCategoryToEnum(vector[3]);
    
    
    
    // Convert priority level string into its enum pairing.
    
    Priority priority_level = mapprioToEnum(vector[4]);
    
    // Ingredient::Ingredient(string name, Date expiry_date, int quantity, Food_class category){
    Ingredient ingredient = Ingredient(name,expiry_date, quantity, category);
    ingredient.set_priority(priority_level);
    return ingredient;
}



//      Sending and receiving functions, from and to, the server.

//Fridge ServerUser::get_fridge() { //
//    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
//    double_vector fridge_vector = new_cli.call("get_fridge", username, password).as<double_vector>(); 
//    std::vector<Ingredient> vector_Ingredient;

//    for (size_t i = 0; i < fridge_vector.double_vect.size(); ++i) {

//        vector<string> ingredient = fridge_vector.double_vect[i];
//        vector_Ingredient.push_back(ingredient_from_vector(ingredient));
//    }

//    return Fridge(vector_Ingredient);
//}



//void ServerUser:: update_fridge(Fridge &f_input) {
//    vector<vector<string>> fridge_as_string_vector;

//    vector<Ingredient> ingredient_list = f_input.get_list();

//    for (size_t i = 0; i < ingredient_list.size(); ++i){
//        vector<string> ingredient = ingredient_to_vector(ingredient_list[i]);  // Pass the current Ingredient object
//        //verify allowed characters or not:
//        for (vector<string>::iterator it= ingredient.begin(); it != ingredient.end(); it++) {
//            if (char_to_exclude_satisfied(*it) == false) {
//                throw std::invalid_argument("Banned characters are present. Try again.");
//                return;
//            }
//        }
//        //add back to fridge vector, if works.
//        fridge_as_string_vector.push_back(ingredient);
//    }
//    //convert to struct:
//    double_vector fridge_as_struct;

//    //send as new format
//    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
//    new_cli.call("update_fridge", username, password, fridge_as_struct);
//}



//// To re-do !!



//vector<Offer> ServerUser::get_offer_list() {  //  [[Ingredient_vector1, [PRICE1]], [Ingredient_vector2, [PRICE2]], ... ,]
//    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);

//    triple_vector offer_list_vector;
//    offer_list_vector.triple_vect = new_cli.call("get_fridge", username, password).as<triple_vector>().triple_vect;

//    //    double doubleValue = std::stod(numericalString);
//    std::vector<Offer> vector_offer;

//    for (size_t i = 0; i < offer_list_vector.triple_vect.size(); ++i) {
//        Offer offer_i(ingredient_from_vector(offer_list_vector.triple_vect[i][0]));
//        double price = std::stod(offer_list_vector.triple_vect[i][1][0]);
//        offer_i.set_price(price);
//        vector_offer.push_back(offer_i);
//    }
//    return vector_offer;
//}


//void ServerUser::update_offer_list(vector<Offer> &offer_list) {
//    //Oscar work yo magiiiic: same format as get_offer_list for the data we want to give to the server.
//    // vector<Offer> --> [[Ingredient_vector1, [PRICE1]], [Ingredient_vector2, [PRICE2]], ... ,]

//    vector<vector<vector<string>>> update_offer_as_string;
//    for (size_t j = 0; j < offer_list.size(); ++j){
//        Offer offer_elem =  offer_list[j];

//        // deal with price
//        double price = offer_elem.get_price();
//        string string_price = to_string(price);

//        vector<string> price_vector;

//        price_vector.push_back(string_price);


//        // deal with Ingredient
//        Ingredient ingredient_offer = offer_elem.get_ingredient();


//        vector<string> ingredient_vector = ingredient_to_vector(ingredient_offer);

//        //Check banned characters.
//        for (vector<string>::iterator it= ingredient_vector.begin(); it != ingredient_vector.end(); it++) {
//            if (char_to_exclude_satisfied(*it) == false) {
//                throw std::invalid_argument("This contains a comma, which is a banned character.");
//                return;
//            }
//        }
//        vector<vector<string>> ingredient_price;

//        ingredient_price.push_back(ingredient_vector);
//        ingredient_price.push_back(price_vector);

//        update_offer_as_string.push_back(ingredient_price);
//        }


//    // Convert to a struct format before sending.
//    triple_vector offer_as_struct_vector(update_offer_as_string);


//    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
//    new_cli.call("update_offer_list", username, password, offer_as_struct_vector);

//}


//int test_msgpack(){




//    /*
//    vector<vector<vector<string>>> ex_offer_list;

//    vector<vector<string>> ingredient_price ;

//    vector<string> ingredient;

//    vector<string> price;



//    vector<string> ingredient.push_back("apple");
//    vector<string> ingredient.push_back("11.11.2005");
//    vector<string> ingredient.push_back("25kg");
//    vector<string> ingredient.push_back("meat");
//    vector<string> ingredient.push_back("red");

//    vector<string> price.push_back("11$");

//    ingredient_price.push_back(ingredient);
//    ingredient_price.push_back(price);
//    ex_offer_list.push_back(ingredient_price);
//    */

//    Offer offer;
//    offer.set_ingredient(Ingredient("apple", Date(24,6,2004) , 1, drink));
//    offer.set_price(1.5);
//    vector<Offer> offer_vector;
//    offer_vector.push_back(offer);

//    ServerUser srv1_usr("oscar", "123");

//    srv1_usr.update_offer_list(offer_vector);



//return 1;


//    // [name, expiry_date, quantity, category, priority_level]


//}



//int var = test_msgpack();


//CLIENT_SIDE MAIN FUNCTION, FOR TESTSING ONLY: not main, but almost main.
int test2 () {
    
    
    //test1: fridge sending/receiving:
    vector<string> ingr1 = {"name", "exp", "date", "cat1", "prior"};
    vector<vector<string>> fridge_test;
    fridge_test.push_back(ingr1);
    fridge_test.push_back(ingr1);
    //send through to server
    rpc::client new_cli("localhost", 8080);
    new_cli.call("test_sending_ingredient_vector_edition", ingr1);
    
    
}

//int val =test2();







