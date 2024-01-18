#include <iostream>
#include <string>
#include<vector>

#include "rpc/client.h"
#include "rpc_client_side.hpp"


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
    basic_data.food_and_dietary_restrictions = usr.get_food_and_dietary_restrictions();
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
        {"gluten", gluten},
        {"fruit", fruit},
        {"vegetable", vegetable},
        {"drink", drink},
        {"lactose", lactose},
        {"canned", canned},
        {"eggs", eggs},
        {"meat", meat},
        {"halal_meat", halal_meat},
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
        {Food_class::gluten, "gluten"},
        {Food_class::fruit, "fruit"},
        {Food_class::vegetable, "vegetable"},
        {Food_class::drink, "drink"},
        {Food_class::lactose, "lactose"},
        {Food_class::canned, "canned"},
        {Food_class::eggs, "eggs"},
        {Food_class::meat, "meat"},
        {Food_class::halal_meat, "halal_meat"},
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






//LIST of chars to exclude: currently, only comma to exclude.
char char_exclude_list[9] = {","};
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

std::unordered_map<std::string, std::vector<std::vector<std::vector<std::string>>>>
get_all_clients_with_offers() {
    rpc::client cl(HOST_SERVER_NAME, HOST_SERVER_PORT);
    
    // Perform an RPC call to the server to retrieve all clients with their offers
    auto clientsWithOffers = cl.call("getMapOfOffers").as<
        std::unordered_map<std::string, std::vector<std::vector<std::vector<std::string>>>>
        >();
    
    
    return clientsWithOffers;
}



//    Sending and receiving functions, from and to, the server.

Fridge ServerUser::get_fridge() { //
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    vector<string> fridge_vector_as_single = new_cli.call("get_fridge", username, password).as<vector<string>>();
    std::vector<Ingredient> vector_Ingredient;
    
    //CONVERT TO DOUBLE VECTOR, THEN: Deserialize
    vector<vector<string>>fridge_vec_as_double= deserialize_fridge(fridge_vector_as_single);
    for (size_t i = 0; i < fridge_vec_as_double.size(); ++i) {
        
        vector<string> ingredient = fridge_vec_as_double[i];
        vector_Ingredient.push_back(ingredient_from_vector(ingredient)); //vector_ingredient type Ingredient
        
    }
    
    return Fridge(vector_Ingredient);
}



void ServerUser:: update_fridge(Fridge &f_input) {
    vector<vector<string>> fridge_as_string_vector;
    
    vector<Ingredient> ingredient_list = f_input.get_list();
    
    for (size_t i = 0; i < ingredient_list.size(); ++i){
        vector<string> ingredient = ingredient_to_vector(ingredient_list[i]);  // Pass the current Ingredient object
        //verify allowed characters or not:
        for (vector<string>::iterator it= ingredient.begin(); it != ingredient.end(); it++) {
            if (char_to_exclude_satisfied(*it) == false) {
                throw std::invalid_argument("Banned characters are present. Try again.");
                return;
            }
        }
        //add back to fridge vector, if works.
        
        fridge_as_string_vector.push_back(ingredient);
    }
    //convert to serialized vec<string>:
    
    
    vector<string> serialized_fridge = serialize(fridge_as_string_vector);
    
    //send as new format
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_fridge", username, password, serialized_fridge);
}



//// To re-do !!


// working on vector<Offer> ;



vector<Offer> ServerUser::get_offer_list() {  //  [[Ingredient_vector1, [PRICE1]], [Ingredient_vector2, [PRICE2]], ... ,]
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    
    vector<string> offer_list_vec_as_single;
    offer_list_vec_as_single = new_cli.call("get_fridge", username, password).as<vector<string>>();
    
    //DESERIALIZE vector of offers:
    vector<vector<vector<string>>> offer_list_vec_as_triple;
    //    double doubleValue = std::stod(numericalString);
    std::vector<Offer> vector_offer;
    
    for (size_t i = 0; i < offer_list_vec_as_triple.size(); ++i) {
        Offer offer_i(ingredient_from_vector(offer_list_vec_as_triple[i][0]));
        double price = std::stod(offer_list_vec_as_triple[i][1][0]);
        offer_i.set_price(price);
        vector_offer.push_back(offer_i);
    }
    return vector_offer;
}


void ServerUser::update_offer_list(vector<Offer> &offer_list) {
    //Oscar work yo magiiiic: same format as get_offer_list for the data we want to give to the server.
    // vector<Offer> --> [[Ingredient_vector1, [PRICE1]], [Ingredient_vector2, [PRICE2]], ... ,]
    
    vector<vector<vector<string>>> update_offer_as_string;
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
        
        //Check banned characters.
        for (vector<string>::iterator it= ingredient_vector.begin(); it != ingredient_vector.end(); it++) {
            if (char_to_exclude_satisfied(*it) == false) {
                throw std::invalid_argument("This contains a comma, which is a banned character.");
                return;
            }
        }
        vector<vector<string>> ingredient_price;
        
        ingredient_price.push_back(ingredient_vector);
        ingredient_price.push_back(price_vector);
        
        update_offer_as_string.push_back(ingredient_price);
    }
    
    
    // Serialize to vector
    vector<string> serialized_offer;
    
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_offer_list", username, password, serialized_offer);
    
}




int test_send_vec_string() {
    vector<string> vec_for_testing = {"ingredient_name", "ingr_dat", "ingr_qty", "ingr_cat", "ingr_prio_level"};
    rpc::client new_client(HOST_SERVER_NAME, HOST_SERVER_PORT);
    vector<string> returned_vec = new_client.call("test_sending_ingredient_as_vec", vec_for_testing).as<vector<string>>();
    cout << returned_vec[0] << endl;
    return 1;
}


//CLIENT_SIDE MAIN FUNCTION, FOR TESTSING ONLY:
int main () {
    
    cout << "hello, it opens" << endl;
    int val1 = test_send_vec_string();
    
    
}







