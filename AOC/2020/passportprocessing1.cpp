// password problem 

#include <iostream>   
#include <vector> 
#include <string> 
#include <sstream> 
#include <set> 
using namespace std ;   

bool isValid(const string &block) {  // here const is used to avoid block getting updated it keeps it constant 
    stringstream ss(block) ; 
    string field ; 

    set<string> keys ; 

    while( ss >> field ) { 
        // take all the fields ony by one and extract the keys  
        size_t pos = field.find(":") ; 
        if( pos == string::npos ) continue ;  

        string key = field.substr( 0 , pos ) ;  // here pos specifies the size / length  

        keys.insert(key) ; 
    }  

    static const vector<string> required = { // static here keeps using the same vector at each call no reallocation 
        "byr","iyr","eyr","hgt","hcl","ecl","pid"
    }; 

    for( const string &k : required ) { 
        if( !keys.count(k) ) return false ; 
    } 

    return true ; 
}

int main() { 
    string line ; // for each line 
    string current ; // for all the passport fields trying to keep all the ones separate with this current pointer 

    int validCount = 0 ;  

    while( getline(cin , line) ) { 
        if( line.empty() ) { // if the line is empty 
            if( !current.empty() ) { 
                // check for the valid passports and increase the validCount 
                if(isValid(current)) validCount++ ; 
                current.clear() ; 
            }
        } else { 
            // if the next line is not empty   
            if( !current.empty() ) current += " " ;  
            current += line ; 
        } 
    } 

    if( !current.empty() ) { 
        // check for the validity of the last passport 
        if(isValid(current)) validCount++ ; 
    }


    cout << validCount << endl; 
} 



