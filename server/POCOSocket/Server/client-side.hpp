#ifndef Error in " Cpp.headerGuard('C:/Users/adamn/OneDrive/Desktop/L'X School/SEM3/CSE201 C++/FoodSaver Testing Branch/FoodSaver/server/POCOSocket/Server/client-side.hpp')": SyntaxError: Expected token `)'
#define Error in " Cpp.headerGuard('C:/Users/adamn/OneDrive/Desktop/L'X School/SEM3/CSE201 C++/FoodSaver Testing Branch/FoodSaver/server/POCOSocket/Server/client-side.hpp')": SyntaxError: Expected token `)'

#endif // Error in " Cpp.headerGuard('C:/Users/adamn/OneDrive/Desktop/L'X School/SEM3/CSE201 C++/FoodSaver Testing Branch/FoodSaver/server/POCOSocket/Server/client-side.hpp')": SyntaxError: Expected token `)'

#include <string>

class ServerUser {
public:
    ServerUser(std::vector<std::string> *login_details);
    ~ServerUser();
    bool addUser();
    
    template<typename JSON_Type> //maybe change to File_Type after we get oscar to fix his lil mess later... :)
    void addItem(JSON_Type file);
private:
    std::vector<std::string> *login_details; //username, password
    rpc::client client;
    std::string ip_address = "127.0.0.1"; //HAVE to figure out how to get right ip address for server connection later.
    //This ip is the server ip!
};


template<typename JSON_Type>
void addItem(JSON_Type file) {
    client.call("addItem", &*login_details, file);
}
