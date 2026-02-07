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

using namespace std ; 

vector<vector<string>> findLadders(string beginWord , string endWord , vector<string> &wordList) {
    unordered_set<string> st(wordList.begin() , wordList.end()) ; 

    queue<vector<string>> q ; 
    q.push({beginWord}) ; 

    vector<string> usedOnLevel ; 
    usedOnLevel.push_back(beginWord) ; 

    vector<vector<string>> ans ; 

    int level = 0 ; 

    while( !q.empty() ) {
        vector<string> vec = q.front() ; 
        q.pop() ; 

        // using this block of code to remove the words that are used in the previous level 
        if( vec.size() > level ){
            level++ ; 
            for(auto it : usedOnLevel ) {
                st.erase(it) ;  
            } 
            usedOnLevel.clear() ; 
        } 

        string word = vec.back() ; 

        if( word == endWord ){
            if( ans.size() == 0 ) {
                ans.push_back(vec) ; 
            } 
            else if( ans[0].size() == vec.size() ) {
                ans.push_back(vec) ; 
            }        
        } 

        for(int i=0 ; i<word.size() ; i++) {
            char original = word[i] ; 

            for(char ch = 'a' ; ch <= 'z' ; ch++) {
                word[i] = ch ; 

                if( st.find(word) != st.end() ) {
                    vec.push_back(word) ; 
                    q.push(vec) ; 
                    usedOnLevel.push_back(word) ;  
                    vec.pop_back() ; 
                }
            }

            word[i] = original ; 
        }       
    }

} 

int main() {

}