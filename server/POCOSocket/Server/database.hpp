#ifndef Error in " Cpp.headerGuard('C:/Users/adamn/OneDrive/Desktop/L'X School/SEM3/CSE201 C++/FoodSaver Testing Branch/FoodSaver/server/POCOSocket/Server/database.hpp')": SyntaxError: Expected token `)'
#define Error in " Cpp.headerGuard('C:/Users/adamn/OneDrive/Desktop/L'X School/SEM3/CSE201 C++/FoodSaver Testing Branch/FoodSaver/server/POCOSocket/Server/database.hpp')": SyntaxError: Expected token `)'

#endif // Error in " Cpp.headerGuard('C:/Users/adamn/OneDrive/Desktop/L'X School/SEM3/CSE201 C++/FoodSaver Testing Branch/FoodSaver/server/POCOSocket/Server/database.hpp')": SyntaxError: Expected token `)'

#include <iostream>

/*  
Simple idea: code a database class, where we code all the data adding etc.
Then, we include this in main:
Also, we get to separate our work so the people grading have an easier time working with us.

 */


class Database {
public:
    Database();
    ~Database();
    template<typename JSON_Type>
    void store_item(std::vector<std::string> *login_details, JSON_Type file); //add this item to this user's file system , or smth like that :)
    
private:
    std::vector<std::string> *user_list = new std::vector<std::string>; 
    
};


template<typename JSON_Type>
void Database::store_item(std::vector<std::string> *login_details, JSON_Type file) {
    
}
