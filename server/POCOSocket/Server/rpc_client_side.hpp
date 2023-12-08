#include <iostream>
#include "rpclib-master/include/rpc/client.h"



//Backend guys make a new user, which asks for functions to be called from serverside! All functions here are focused on getting server-coded functions called.
//Client connection:

class User {
               
public:
    
//Creates a user for temporary Use.
    User(std::string username, std::string psswd);
    
    ~User();

//createClient will add user data, login, to the server. Checks it isnt already in use, makes hash to give user so he can only access his own data.
//login details given as a list of 2 strings. 1 means user added, 0 means user not added.
    bool addNewUser();

    
//Then, we open a session. This checks login details, if valid, opens a session with specific access.
    bool openSession();

//and to close a session
    bool closeSession();

//Client sending specific data types. Template function, we can implement differently for each file type- store food in different place to full fridge upload etc.
//Make sure to add a category in json file which says YO my hash num is this.
    template<typename File_Type>
    bool upload_file(File_Type file);


//Client asking for data to be received, chooses which type !!Types to be decided still.
    template <typename File_Type>
    File_Type receive_file(std::string file_name);
    
    template <typename File_Type>
    bool delete_file(std::string file_name);

private:
    std::vector<std::string> *login_details;

};
