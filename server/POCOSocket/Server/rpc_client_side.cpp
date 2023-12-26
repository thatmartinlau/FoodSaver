#include <string>
#include<vector>
#include <sstream>
#include "rpc/client.h"
#include "rpc_client_side.hpp"
#include "../../../test3/front.hpp"
#include "../../../test3/ingredient.h"
#include "../../../test3/date.h"
#include "../../../test3/fridge.h"
#include "../../../test3/offer.h"

using namespace std;

string HOST_SERVER_NAME = "127.0.0.1"; //change to Server later.
int HOST_SERVER_PORT = 3333;

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

void ServerUser::update_user(string new_username, string new_password) {
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_user", username, password, new_username, new_password);
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


//OSCAR's CODE ADAPTED BY ADAM: Oscar, feel free to adjust and change if u have a way which matches smth u prefer to use.
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

//.//////New Types for data transfer:
struct offer_list_vector {
    vector<vector<vector<vector<string>>>> offer_list;
    MSGPACK_DEFINE_ARRAY(offer_list)
};

struct fridge_vector {
    vector<vector<string>> fridge_vector;
    MSGPACK_DEFINE_ARRAY(fridge_vector)
};



//.//////Server send-receive functions.

Fridge ServerUser::get_fridge() { //
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    fridge_vector fridge_vector1 = new_cli.call("get_fridge", username, password).as<fridge_vector>(); //vector of ingredients, each as a vector of strings.
    //Oscar work yo magic
    //     Fridge(std::list<Ingredient> init_list);
    std::vector<Ingredient> vector_Ingredient;

    for (size_t i = 0; i < fridge_vector1.size(); ++i) {

        vector<string> ingredient = fridge_vector1[i];
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



vector<Offer> ServerUser::get_offer_list() {
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    vector<vector<vector<vector<string>>>> offer_list_vector = new_cli.call("get_offer_list", username, password);
    //Oscar work yo magic: ADDED DETAIL: The offer list format holds offers, each other has this format exactly: [vector<string>, vector<string>], Where the second vector stores only a double!
    //That double represents the price of the offer. We needed this because vectors have homogenous type. (only store one type.)
    
    //    double doubleValue = std::stod(numericalString);
    std::vector<Offer> vector_offer;


    for (size_t i = 0; i < offer_list_vector.size(); ++i) {
        double price = std::stod(offer_list_vector[i][1][0][0]);
        // offer_list[i][0] convert into a vector of ingredient .

        std::vector<Ingredient> vector_offer_list;

        for (size_t j = 0; j < offer_list_vector[i][0].size(); ++i) {
            vector_offer_list.push_back(ingredient_from_vector(offer_list_vector[i][0][j]));
        }

        Offer offer = Offer(vector_offer_list);
        offer.set_price(price);
        vector_offer.push_back(offer);
    }
    return vector_offer;
}


void ServerUser::update_offer_list(vector<Offer> &offer_list) {
    //Oscar work yo magiiiic: same format as get_offer_list for the data we want to give to the server.
    // vector<Offer> -->
    // [ [ [ [name1, quantity1, category1, expiry_date1, priority_level1], [name2, quantity2, category2, expiry_date2, priority_level2], ...], [[price]] ],  .... ,[ [ [name1', quantity1', category1', expiry_date1', priority_level1'], [name2', quantity2', category2', expiry_date2', priority_level2'], ...], [[price']] ]
    // [[Ingredient list1, price1] , [Ingredient list 2, price2] ,...]
    vector<vector<vector<vector<string>>>> update_offer;
    for (size_t j = 0; j < offer_list.size(); ++j){
        Offer offer_elem =  offer_list[j];
        double price = offer_elem.get_price();
        string string_price = to_string(price);
        //Offer(std::vector<Ingredient> ingredient_list);
        vector<Ingredient> list_ingredient = offer_list[j].get_ingredient_list(); // ask for sixtine for such a method in class offer
        vector<vector<string>> update_list_ingredient;
        //ingredient_to_vector(Ingredient)
        for(size_t i = 0; i<list_ingredient.size(); i++){
            update_list_ingredient.push_back(ingredient_to_vector(list_ingredient[i]));

        }
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
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_offer_list", username, password, update_offer); //this in the weird new vector<vector<vector<vector<string>>>> format, sorry! Check telegram paper image n1 for clarity, hopefully :)

}






