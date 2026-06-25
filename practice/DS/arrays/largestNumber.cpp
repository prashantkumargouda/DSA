// LARGEST NUMBER 

#include <bits/stdc++.h> 
using namespace std ; 

static bool cmp( string &a , string &b ) {
    return a + b > b + a ; 
} 


string largest(vector<int> &nums) {
    vector<string> temp ; 

    for(int num : nums) {
        temp.push_back(to_string(num)) ;  
    } 

    sort( temp.begin() , temp.end() , cmp) ;   

    /* 
        sort(temp.begin() , temp.end() , 
        [](string &a , string &b) {
            return a + b > b + a ; 
        }) ;
    */
    if( temp[0] == "0" ) {
        return "0" ; 
    } 

    string str = "" ; 

    for(string &s : temp) {
        str += s ; 
    } 

    return str ; 
}