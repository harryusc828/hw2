#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "datastore.h"
#include "util.h"
#include <deque> 
#include <map>

class MyDataStore: public DataStore{

public: 
    ~MyDataStore(); 

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    // Adding the hit_num th item in the hit_vec vector to the user's cart
    void add_cart(string user, int hit_num, vector<Product*> hit_vec);


    void view_cart(string user);


    void buy_cart(string user); 



private: 
    set<Product*> product_set;
    map<User*, deque<Product*>> user_map; 

}; 

#endif