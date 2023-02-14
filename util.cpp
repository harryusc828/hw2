#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{

    //cout << "line 19 the raw word is" << rawWords << endl; 
    set<string> my_words;
    int idx_1 = 0; 
    for (size_t i = 0; i < rawWords.size(); i ++){
        //if(i == rawWords.size())



        if( ((rawWords[i] <= 'Z' && rawWords[i] >= 'A') || (rawWords[i] >= 'a' && rawWords[i] <= 'z')) && (i != rawWords.size()-1) ){
            continue;
        }
        else if(i == rawWords.size()-1){
            int idx_2 = i;
            if ((idx_2 -idx_1) >= 2){
                my_words.insert(convToLower(rawWords.substr(idx_1, idx_2 -idx_1 +1)));
            }
            idx_1 = idx_2 +1; 
        }
        else {
            int idx_2 = i;
            if ((idx_2 - idx_1) >= 2){
                my_words.insert(convToLower(rawWords.substr(idx_1, idx_2 - idx_1)));
            }
            idx_1 = idx_2 + 1; 
        }
    }
    
    for(set<string>::iterator it = my_words.begin(); it != my_words.end(); ++it){
       cout <<"Line 35" << *it << endl; 
   }
    //cout << "line 37 end" << endl; 
    return my_words; 
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
