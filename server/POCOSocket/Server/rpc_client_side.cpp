#include "rpc/client.h"
#include <string>
#include "rpc_client_side.hpp"
#include<vector>
#include "../../../test3/front.hpp"

using namespace std;

string HOST_SERVER_NAME = "127.0.0.1"; //change to Server later.
int HOST_SERVER_PORT = 3333;

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
vector<string> ingredient_to_vector(Ingredient &ingr) { //returns vector as [name, quantity, category, expiry_date, priority_level], all as string s.
    vector<string> vec;
    vec.push_back(ingr.get_name());
    vec.push_back(to_string(ingr.get_Quantity()));
    std::string cat_string(foodClassToString(ingr.get_FoodClass())); // Convert std::string_view to std::string
    vec.push_back(cat_string);
    vec.push_back(ingr.get_expiry_date()); // need Sixtine's get_expiry date
    string priority_level_string = nameof(ingr.priority_level);
    vec.push_back(ingr.priority_level);
    return vec;
}






Ingredient ingredient_from_vector(std::vector<std::string> vector) { //Oscar work yo magic
 // Convert string name into --> string name --> nothing to change
    std::string name = vector[0];

    // Convert string quantity into --> int quantity :
    int quantity = std::stoi(vector[1]);

    // Convert string category into --> in food class enum

    Food_class category = mapCategoryToEnum(vector[2]);

    // Convert string expiry_date --> string --> nothing to change

    std::string expiry_date =vector[3];

    // Convert priority level string into --> enum

    Priority priority_level = mapprioToEnum(vector[4]);


    Ingredient ingredient = Ingredient(name,category,expiry_date);
    ingredient.set_priority(priority_level);
    return ingredient;
}

Fridge ServerUser::get_fridge() { // [[]]
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    std::vector<vector<string>> fridge_vector = new_cli.call("get_fridge", username, password); //vector of ingredients, each as a vector of strings.
    //Oscar work yo magic
    //     Fridge(std::list<Ingredient> init_list);
    std::vector<Ingredient> vector_Ingredient;

    for (size_t i = 0; i < fridge_vector.size(); ++i) {
        vector_Ingredient.push_back(ingredient_from_vector(fridge_vector[i]));
    }

    return Fridge(vector_Ingredient);

}


void ServerUser::update_fridge(Fridge &f_input) {
    //convert to database-wanted format: OSCAR'S METHOD
    vector<vector<string>> fridge;
    for (list<Ingredient>::iterator i = f_input.ingredient_list.begin(); i != f_input.ingredient_list.end(); i++) {
        
        //convert ingredient to vector format USING OSCAR's CODE
        vector<string> ingredient;
        fridge.push_back(ingredient_to_vector(ingredient));
    }
    //send as new format
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_fridge", username, password, fridge_vector);
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

        for (size_t j = 0; j < offer_list[i][0].size(); ++i) {
            vector_offer_list.push_back(ingredient_from_vector(offer_list[i][0][j]));
        }

        Offer offer = Offer(vector_offer_list);
        offer.set_price(price);
        vector_offer.push_back(offer);
    return vector_offer;










    }



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









    }
    rpc::client new_cli(HOST_SERVER_NAME, HOST_SERVER_PORT);
    new_cli.call("update_offer_list", username, password, new_offer_list); //this in the weird new vector<vector<vector<vector<string>>>> format, sorry! Check telegram paper image n1 for clarity, hopefully :)







}






