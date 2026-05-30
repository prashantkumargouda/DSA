// maximum length of subarray with k unique elements 

#include <bits/stdc++.h> 
using namespace std ; 

/* 
    [1, 2, 3, 2, 2] 

*/

// brute force approach 
int totalFruits(vector<int> &fruits) {
    int maxCount = 0 ; 
    
    for(int i=0 ; i<fruits.size() ; i++){
        int count = 0 ; 
        unordered_map<int , int> basket ; 
        for(int j=i ; j<fruits.size() ; j++){
            basket[fruits[j]]++ ;  // increase the count for the fruit   
            
            if( basket.size() > 2 ) {
                break ;
            }
            count++ ; 
        } 

        maxCount = max( maxCount , count ) ;
    }   

    return maxCount ; 
} 

//better approach 
int totalFruits2(vector<int> &fruits) {
    int maxCount = 0 ; 
    int left = 0 ; 

    unordered_map<int , int> basket ;  

    for(int right = 0 ; right < fruits.size() ; right++){  
        basket[fruits[right]]++ ; 

        while( basket.size() > 2 ) {
            basket[fruits[left]]--;  

            if( basket[fruits[left]] == 0 ) {
                basket.erase(fruits[left]) ;
            } 
            left++ ;
        }
        maxCount = max(maxCount , right - left + 1) ;     
    } 

    return maxCount ; 
}  

// Optimal Approach 
int totalFruits3(vector<int> &fruits) {
    int maxLen = 0 ; 

    int lastfruit = -1 , secondlastfruit = -1 ; 
    int currCount = 0 , lastfruitstreak = 0 ; 

    for(int fruit : fruits) {
        if( fruit == lastfruit || fruit == secondlastfruit ){
            currCount++ ; 
        } 
        else {
            currCount = lastfruitstreak + 1 ; 
        } 

        if( fruit == lastfruit ) {
            lastfruitstreak+=1; 
        } 
        else{ 
            lastfruitstreak = 1 ;
            secondlastfruit = lastfruit ; 
            lastfruit = fruit ; 
        } 
        maxLen = max( maxLen , currCount ) ; 
    } 
    return maxLen ; 
}

 
