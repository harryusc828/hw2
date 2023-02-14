#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"
#include <sstream>

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string ISBN, string author):
    Product::Product(category, name, price, qty),
    author_(author),
    ISBN_(ISBN)
{

}

Book::~Book()
{

}




set<string> Book::keywords() const
{
    set<string> book_keys = parseStringToWords(name_);
    set<string> temp = parseStringToWords(author_); 
    book_keys = setUnion(book_keys, temp);
    book_keys.insert(convToLower (ISBN_));
    return book_keys; 

}

string Book::displayString() const
{
    string book_string = "";
    book_string += name_;
    book_string += "\n";
    book_string += "Author: ";
    book_string += author_;
    book_string += " ISBN: ";
    book_string += ISBN_;
    book_string += "\n";
    ostringstream streamObj;
    streamObj << price_;
    string strObj = streamObj.str();


    book_string += strObj;
    book_string += " ";
    book_string += to_string(qty_);
    book_string += " left. ";
    return book_string; 
}




void Book::dump(ostream& os) const
{
    Product::dump(os);
    os << ISBN_ << "\n" << author_ << endl; 
}