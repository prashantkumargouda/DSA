// 126. Word Ladder II

// Hard

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

#include <iostream> 
#include <queue> 
#include <vector>
#include <unordered_set> 
#include <unordered_map> 

using namespace std ; 

// this below solution gives TLE for leetcode
 
// vector<vector<string>> findSequences(string beginWord , string endWord , vector<string> &wordList) {
//     unordered_set<string> st( wordList.begin() , wordList.end() ) ; 

//     vector<vector<string>> ans ; 

//     queue<vector<string>> q ; 
//     q.push({beginWord}) ; 

//     vector<string> usedOnLevel ; 
//     usedOnLevel.push_back(beginWord) ; 

//     int level = 0 ; 

//     while( !q.empty() ) { 
//         // queue storing the vectors of strings 
//         vector<string> vec = q.front() ; 
//         q.pop() ; 

//         if( vec.size() > level ) {
//             level++ ; 
//             for( auto it : usedOnLevel ) {
//                 st.erase(it) ; 
//             } 
//             usedOnLevel.clear() ; 
//         }   

//         string word = vec.back() ; 

//         if( word == endWord ){
//             if( ans.size() == 0 ) {
//                 ans.push_back(vec) ; 
//             } 
//             else if( ans[0].size() == vec.size() ) {
//                 ans.push_back(vec) ; 
//             }
//         } 

//         for(int i=0 ; i<word.size() ; i++) {
//             char original = word[i] ; 

//             for(char ch = 'a' ; ch <= 'z' ; ch++) {
//                 word[i] = ch ; 
                
//                 if( st.find(word) != st.end() ) {
//                     vec.push_back(word) ; 
//                     usedOnLevel.push_back(word) ; 
//                     q.push(vec) ; 
//                     vec.pop_back() ; 
//                 }
//             } 

//             word[i] = original ; 
//         }
//     } 
    
//     return ans ; 
// } 

// 
 

//  optimised version 

// what I need is a : unordered_map , unordered_set , queue storing the words 

unordered_map<string,int> mpp ;
vector<vector<string>> findLadders(string beginWord , string endWord, vector<string> &wordList) {
    unordered_set<string> st( wordList.begin() , wordList.end() ) ; 
    queue<string> q ; 
    q.push(beginWord) ; 

    mpp[beginWord] = 1 ;  
    
    while( !q.empty() ) {
        string word = q.front() ;
        int steps = mpp[word] ; 
        q.pop() ; 

        
    }

} 

int main() {

}