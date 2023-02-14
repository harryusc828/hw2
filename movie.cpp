#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"
using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating):
    Product::Product(category, name, price, qty),
    genre_(genre),
    rating_(rating)
{

}

Movie::~Movie()
{

}




set<string> Movie::keywords() const
{
    set<string> movie_keys = parseStringToWords(name_);
    movie_keys.insert(genre_);
    //set<string> temp = parseStringToWords(genre_);
    //movie_keys = setUnion(movie_keys, temp);
    return movie_keys; 
}

string Movie::displayString() const
{
    string movie_string = "";
    movie_string += name_;
    movie_string += "\n";
    movie_string += "Genre: ";
    movie_string += genre_;
    movie_string += " Rating: ";
    movie_string += rating_;
    movie_string += "\n";
    movie_string += to_string(price_);
    movie_string += " ";
    movie_string += to_string(qty_);
    movie_string += "left. ";
    return movie_string; 
}




void Movie::dump(ostream& os) const
{
    Product::dump(os);
    //os << genre_ << "\n" << rating_ << endl; 
    set<string> temp = keywords();
    os << "Line 57" << endl;
    for (set<string>::iterator it = temp.begin(); it != temp.end(); ++it){
        os << *it << endl; 
    }
    return; 

}