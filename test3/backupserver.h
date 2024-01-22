#ifndef BACKUPSERVER_H
#define BACKUPSERVER_H

#include "user.h"

class BackupServer
{
public:
    BackupServer();
    ~BackupServer();
    void add_user(User new_user);
    User remove_user(User *user_to_delete);

private:
    std::vector<User> user_list;
};

#endif // BACKUPSERVER_H
