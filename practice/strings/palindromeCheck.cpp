// reverse words in a given string / palindrome check 

#include <iostream> 
#include <string> 
#include <vector> 
#include <sstream> 

using namespace std ; 

string revereseWords(string str) {
    string word = "" ; 
    vector<string> words ; 

    for(int i=0 ; i< str.size() ; i++) {
        if( str[i] != ' ' ) {
            word += str[i]  ; 
        }else if( !word.empty() ) {
            words.push_back(word) ; 
            word = "" ; 
        }
    } 

    if( !word.empty() ){
        words.push_back(word) ; 
    } 

    reverse( words.begin() , words.end() ) ; 

    string result = "" ; 

    for(int i=0 ; i<words.size() ; i++) { 
        result += words[i] ;   

        if(i < words.size() - 1){ // if it is not the last element  
            result += ' ' ;
        }
    }  

    return result  ; 

}  

string reverseWords(string str) { 
    string result = "" ; 
    
    int i = str.size() - 1 ; 

    while( i >= 0 ) {
        while( i >= 0 && str[i] == ' ' ) {
            i-- ; 
        }  

        int end = i ; 

        while( i >= 0 && str[i] != ' ' ) {
            i-- ; 
        }   

        string word = str.substr( i+1 , end - i ) ; 

        if( !result.empty() ){
            result += ' ' ;
        } 
        result += word ;  
    }

    return result ; 
}

string reverseWords(string str) {
    // using stringstream  

    string word ; 
    vector<string> words;  
    stringstream ss(str); 

    while( ss >> word ) {
        words.push_back(word) ; 
    } 

    reverse( words.begin() , words.end() ) ; 
    string result ; 

    for(int i=0 ; i<words.size() ; i++ ){
        result += words[i] ; 

        if( i != words.size() - 1 ) result += ' ' ; 
    } 

    return result ; 
}

int main() {
    string str ; 
    cin >> str ; 


}