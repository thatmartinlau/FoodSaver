#include "backupserver.h"

BackupServer::BackupServer() {}

BackupServer::~BackupServer() {}

void BackupServer::add_user(User new_user) {
    user_list.push_back(new_user);
}

User BackupServer::remove_user(User *user_to_delete) {
    // Check if offer_to_delete is nullptr
    if (user_to_delete == nullptr) {
        throw std::invalid_argument("Null pointer passed to remove_user");
    }

    for (auto it = user_list.begin(); it != user_list.end(); ++it) {
        if (*it == *user_to_delete) {
            User foundUser = *it;
            user_list.erase(it);
            return foundUser;
        }
    }
}

std::vector<User> BackupServer::get_user_list() {
    return user_list;
}
