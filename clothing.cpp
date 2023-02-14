#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand):
    Product::Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{

}

Clothing::~Clothing()
{

}




set<string> Clothing::keywords() const
{
    set<string> clothing_key = parseStringToWords(name_);;
    clothing_key.insert(brand_);
    return clothing_key; 

}

string Clothing::displayString() const
{
    string clothing_string = "";
    clothing_string += name_;
    clothing_string += "\n";
    clothing_string += "Size: ";
    clothing_string += size_;
    clothing_string += " Brand: ";
    clothing_string += brand_;
    clothing_string += "\n";
    clothing_string += to_string(price_);
    clothing_string += " ";
    clothing_string += to_string(qty_);
    clothing_string += "left. ";
    return clothing_string; 
}




void Clothing::dump(ostream& os) const
{
    Product::dump(os);
    os << size_ << "\n" << brand_ << endl; 
}