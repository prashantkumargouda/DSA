#include <iostream> 
#include <sstream>
#include <string> 
#include <map> 
#include <vector>  
#include <unordered_set> 

using namespace std ;  

bool isNumber(const string& s) { 
    if( s.empty() ) return false ; 

    for(char c : s) { 
        if( !isdigit(static_cast<unsigned char>(c))) return false ;  // isdigit expects unsigned chars only to check for characters are digits or not 
    }  // and chars are small integers of 1 byte which are mapped to characters using character encoding 
     
    return true ; 
} 
 
bool validYear(const string &s , int low , int high ) {  // validate all the field years
    if( s.size() != 4 || !isNumber(s) ) return false ;   
    auto x = stoi(s) ; 
    return low <= x && x <= high ;
} 

bool validHeight(const string& s) {  // validating the heights requires an unit and values to be in some ranges 
    if( s.size() < 3 ) return false ;  

    string numPart = s.substr( 0 , s.size() - 2 )  ; 
    string unit = s.substr( s.size() - 2 ) ;  
    
    if(!isNumber(numPart)) return false ; // isNumber is used to check if a string represents a number or not isDigit for characters digit check 
    int height = stoi(numPart) ;  

    if( unit == "cm" ) { 
        return 150 <= height && height <= 193 ; 
    } 
    else if( unit == "in" ) { 
        return 59 <= height && height <= 76 ; 
    } 

    return false ; 
    
} 

bool ValidHairColor(const string &s) { 
    // starts with a hash # and next 6 characters from 0-6 and a-f  
    if( s.size() != 7 ) return false ;  

    if( s[0] != '#' ) return false ;  

    for(int i=1 ; i<7 ; i++) {
        char c = s[i] ; 
        bool digit = ( c >= '0' && c <= '9' ) ;  
        bool hexlow = ( c >= 'a' && c <= 'f' ) ;  

        if( !digit && !hexlow ) return false ; 
    } 
    
    return true ; 
} 

bool validEyeColor(const string &s) { 
    // here to check for the hair colors out of a set  
    static const unordered_set<string> eyeColor = {
        "amb", "blu", "brn", "gry", "grn", "hzl", "oth"
    };  

    if( !eyeColor.count(s) ) return false ; 
    return true ; 

    // return eyeColor.Contains(s) ; 
    // return eyeColor.count(s) ; 
}

bool validPid(const string &s) { 
    // contains 9 digits  
    if( s.size() != 9 ) return false ; 
    return isNumber(s) ; 
} 


bool isPassportValid(const map<string,string> &fields) {
    // 1) All required keys present
    static const vector<string> required = {
        "byr","iyr","eyr","hgt","hcl","ecl","pid"
    };
    for (const string &k : required) {
        if (!fields.count(k)) return false;
    }

    // 2) Validate each field
    const string &byr = fields.at("byr");
    const string &iyr = fields.at("iyr");
    const string &eyr = fields.at("eyr");
    const string &hgt = fields.at("hgt");
    const string &hcl = fields.at("hcl");
    const string &ecl = fields.at("ecl");
    const string &pid = fields.at("pid");

    if (!validYear(byr, 1920, 2002)) return false;
    if (!validYear(iyr, 2010, 2020)) return false;
    if (!validYear(eyr, 2020, 2030)) return false;
    if (!validHeight(hgt))          return false;
    if (!ValidHairColor(hcl))       return false;
    if (!validEyeColor(ecl))        return false;
    if (!validPid(pid))             return false;

    return true;
}


int main() { 
    ios::sync_with_stdio(false); // these lines used to make the input and output 3x or upto 10x faster 
    cin.tie(nullptr);  

    string line , current ; 
    vector<string> rawPassport ; 

    while( getline(cin , line) ) { 
        if( line.empty() ){ 
            if( !current.empty() ) { 
                rawPassport.push_back(current) ; 
                current.clear() ; 
            }
        } else {  // if there is some more input to be taken for the passport and line is not empty 
            if( !current.empty() ) current += " " ; 
            current += line ; 
        }
    } 

    if( !current.empty() ) { 
        rawPassport.push_back(current) ; 
    } 

    int validCount = 0 ;   // maintaining the valid count here also  

    for(const string &p : rawPassport ) { 
        // extracting the fields key and value 

        stringstream ss(p)  ;  // string stream for the values of p  
        map<string , string> fields ;  

        string token ; 

        while( ss >> token ) {  // tokens are the individual fields of each passport 
            size_t pos = token.find(":") ; 
            if( pos == string :: npos ) continue ; // if : not found  

            string key = token.substr( 0 , pos )  ; 
            string value = token.substr( pos + 1 ) ;   

            fields[key] = value ; // used a map to store the fields and their values in key value pairs ; 
        }  

        if (isPassportValid(fields)) {
            ++validCount;
        } 
    } 

    cout << validCount << endl; 

    return 0 ; 
}