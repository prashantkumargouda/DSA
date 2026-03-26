// finding the top k frequent words 

#include <iostream> 
#include <string>
#include <vector> 
#include <unordered_map> 
#include <algorithm> 
#include <queue>  

using namespace std ;  

vector<string> top(vector<string> &words , int k){
    int n = words.size() ; 
    vector<string> res ;  

    unordered_map< string , int > mp ; 

    for(string word : words) {
        mp[word]++ ; 
    } 

    vector<pair<string ,int>> sorted( mp.begin() , mp.end() ) ; 

    sort( sorted.begin() , sorted.end() , []( const pair<string ,int> &a , const pair<string,int> &b) {
        return a.second > b.second ; 
    }) ;  

    for(int i=0 ; i<k ; i++) {
        res.push_back( sorted[i].first ) ; 
    }   

    reverse( res.begin() , res.end() ) ; 

    return res ; 
} 

vector<string> top1( vector<string> &words ,int k ) {
    int n = words.size() ;  

    // using the pririty queue min heap method 
    
    unordered_map<string , int> mp ;

    for(string &str : words){
        mp[str]++ ;
    }  

    auto cmp = []( const pair<string , int> &a , const pair<string , int> &b) {
        if( a.second != b.second ) {
            return a.second > b.second ; 
        } 
        return a.first < b.first ; 
    } ;  

    // so a priority queue has a syntax of "TypeOfElement" , "Container" , "Comparator" 
    priority_queue<pair<string , int> , vector<pair<string , int>> , decltype(cmp) > pq(cmp) ; 

    for( auto &[word , count] : mp ) {
        pq.push({word , count}) ; 
        if( pq.size() > k ) {
            pq.pop() ; 
        }
    }
    
    vector<string> res(k) ; 
    for(int i=k-1 ; i>=0 ;i--) {
        res[i] = pq.top().first ; 
        pq.pop() ; 
    }

    return res ; 
} 

int main() { 
    vector<string> words = {"i" , "love" , "leetcode" , "i" , "love" , "coding"} ; 

    vector<string> temp = top( words , 2 ) ;   

    for(auto &it : temp) {
        cout << it << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}