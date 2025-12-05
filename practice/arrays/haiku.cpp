#include <iostream> 
#include <string> 
#include <vector> 
#include <cctype>
using namespace std ; 

bool checkVowel(char c){
    c = tolower(c) ; 

    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) ;
}

int countVowels(string line) { 
    int count = 0 ; 
    for(auto c : line) {
        if( checkVowel(c) ) {
            count++ ; 
        }
    } 
    return count ; 
} 

int main() {
    string line ; 
    vector<int> targets = {5,7,5} ; 
    vector<int> counts ;  

    for(int i=0 ; i<3 ; i++) {
        getline(cin , line) ;   
        counts.push_back(countVowels(line)) ; 
    } 

    if( counts == targets ) {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;
    } 

    return 0 ; 
}