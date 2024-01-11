#include "rpc/server.h"
#include "rpc/client.h"
#include <vector>
#include <list>
using namespace std;
//Types to test:
struct offer_list_vector {
    vector<vector<vector<string>>> offer_list;
    MSGPACK_DEFINE_ARRAY(offer_list)
};

struct fridge_vector {
    vector<vector<string>> fridge_vector;
    MSGPACK_DEFINE_ARRAY(fridge_vector)
};

struct single_vector {
    list<bool>  list_of_bools;
    MSGPACK_DEFINE_ARRAY(list_of_bools)
};



void test_sending_vectors(single_vector blabla_to_test) {
    
    rpc::client new_cli("127.0.0.1", 3333);
    new_cli.call("test_sending_vectors", blabla_to_test);
    
}


int main() {
    rpc::server srv(3333);
    
    srv.bind("test_sending_vectors", &test_sending_vectors);
    
    
    srv.run();
    
    return 0;
}


