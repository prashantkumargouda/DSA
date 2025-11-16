// Letter combinations of a phone number 
#include <iostream>
#include <string> 
#include <vector>

using namespace std ; 

// making use of backtracking recursion and mapping to solve the required problem 

void solve(string digits , int i , string output , vector<string> &ans , string mapping[] ) { 
    if( i>= digits.length() ){ 
        ans.push_back(output); 
        return ; 
    } 

    string letters = mapping[digits[i] - '0'] ; 

    for(int j=0 ; j<letters.length() ; j++) { 
        output.push_back(letters[j]) ; 
        solve(digits , i+1 , output , ans , mapping ) ;
        output.pop_back() ; 
    } 
} 

int main() { 
    string digits ; 
    cout << "Enter the digits :" << endl; 

    getline(cin , digits) ;  

    vector<string> ans ;
    string output ; 
    // now mapping the elements 

    string mapping[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; 

    solve(digits , 0 , output , ans , mapping ) ; 

    for( auto &sol : ans ){ 
        cout << sol << " " ; 
    } 
    cout << endl; 

    return 0 ; 

}