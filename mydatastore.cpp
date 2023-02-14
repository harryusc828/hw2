#include "mydatastore.h"
using namespace std;

MyDataStore::~MyDataStore()
{
    // delete all the dynamically allocated products and users
    for(set<Product*>::iterator it = product_set.begin(); it != product_set.end(); ++it){
        delete *it;
    }
    for(map<User*, deque<Product*>>::iterator it = user_map.begin(); it != user_map.end(); ++it){
        delete it->first; 
    }
}

/**
* Adds a product to the data store
*/
void MyDataStore::addProduct(Product* p)
{
    product_set.insert(p);
}

void MyDataStore::addUser(User* u)
{
    deque<Product*> d; 
    user_map.insert(make_pair(u, d));
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
    for(size_t i = 0; i < terms.size(); i++){
        terms[i] = convToLower(terms[i]); 
    }
    vector<Product*> my_vector; 
    set<Product*> temp1;
    set<Product*> temp2; 
    // 0 is and, 1 is or 
    if(type == 0){
        for(size_t i = 0; i < terms.size(); i++){
            for (set<Product*>::iterator it = product_set.begin(); it != product_set.end(); ++it){
                set<string> the_words = (*it)->keywords(); 
                if (the_words.find(terms[i]) != the_words.end()){
                    temp1.insert(*it); 
                }
            }
            if(i == 0){
                temp2 = temp1;
                temp1.clear(); 
                continue; 
            }
            temp2 = setIntersection(temp1, temp2); 
            temp1.clear(); 
        }
    }
    else if (type == 1){
        for(size_t i = 0; i < terms.size(); i++){
            for (set<Product*>::iterator it = product_set.begin(); it != product_set.end(); ++it){
                set<string> the_words = (*it)->keywords(); 
                if (the_words.find(terms[i]) != the_words.end()){
                    temp1.insert(*it); 
                }
            }
            temp2 = setUnion(temp1, temp2); 
            temp1.clear(); 
        }
    }

    for(set<Product*>::iterator it = temp2.begin(); it != temp2.end(); ++it){
        my_vector.push_back(*it);
    }
    //displayProducts(my_vector);
    //for (size_t i = 0; i < my_vector.size(); i++){
      //  cout << "line 68 the content is" << my_vector[i] << endl; 
    //}
    return my_vector; 

}

void MyDataStore::dump(std::ostream& ofile)
{
    ofile << "<products> \n";
    for(set<Product*>:: iterator it = product_set.begin(); it != product_set.end(); ++it){
        (*it) -> dump(ofile); 
        //ofile << "\n"; 
    }
    ofile << "</products> \n";
    ofile << "<users> \n";
    for(map<User*, deque<Product*>>::iterator it = user_map.begin(); it != user_map.end(); ++ it){
        (it->first) -> dump(ofile); 
       //ofile << "\n"; 
    }
    ofile << "</users> \n"; 
}

// Adding the hit_num th item in the hit_vec vector to the user's cart
void MyDataStore::add_cart(string user, int hit_num, vector<Product*> hit_vec)
{
    size_t temp = hit_num; 
    if(hit_vec.size() < temp || temp <= 0){
        cout << "Invalid request" << endl;
        return; 
    }
    for(map<User*, deque<Product*>>::iterator it = user_map.begin(); it != user_map.end(); ++it){
        if((it->first) -> getName() == user){
            (it->second).push_back(hit_vec[hit_num-1]);
            return; 
        }
    }
    cout << "Invalid request" << endl; 
    return; 
}

void MyDataStore::view_cart(string user)
{
    for(map<User*, deque<Product*>>::iterator it = user_map.begin(); it != user_map.end(); ++it){
        if((it -> first) -> getName() == user){
            for(size_t i = 0; i < (it->second).size(); i++){
                    cout << "Item " << i+1 << endl; 
                    cout << (it->second)[i] -> displayString() << endl; 
            }
            return; 
        }
    }
    cout << "Invalid username" << endl; 
    return; 
}

void MyDataStore::buy_cart(string user)
{
    //int del_count = 0; 
    for (map<User*, deque<Product*>>::iterator it = user_map.begin(); it != user_map.end(); ++it){
        if((it -> first) -> getName() == user){
            User* temp_user = it->first; 
            deque<Product*> temp; 
            while((it->second).size() != 0){
                cout << (it->second).size() << "is the size" << endl; 
                if (temp_user -> getBalance() >= (it->second)[0] -> getPrice() && (it->second)[0] -> getQty() != 0){
                    temp_user -> deductAmount((it->second)[0] -> getPrice()); 
                    (it->second)[0] -> subtractQty(1);
                    
                }
                else{
                    temp.push_back(it->second[0]); 
                }
                (it->second).pop_front(); 
            }
            it -> second = temp; 
            return; 
        }

    }
    cout << "Invalid username" << endl; 
    return; 
}