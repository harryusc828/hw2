#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
#include <sstream>

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
    set<string> clothing_key = parseStringToWords(name_); 
    set<string> brand = parseStringToWords(brand_);
    
    return setUnion(clothing_key, brand); 

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
    ostringstream streamObj;
    streamObj << price_;
    string strObj = streamObj.str();


    clothing_string += strObj;
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