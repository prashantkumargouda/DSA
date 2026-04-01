#include <iostream>  
#include <vector> 
#include <climits> 
#include <algorithm> 

using namespace std ; 

int check(int day , vector<vector<int>> &task , int last ) {
    if( day == 0 ) {
        int maxi = INT_MIN ; 
        for(int i=0 ; i<3 ; i++) {
            if( i != last ) {
                maxi = max( maxi , task[day][last] ) ; 
            }
        } 

        return maxi ; 
    }  

    int maxi = INT_MIN ; 

    for(int i=0 ; i<3 ; i++) {
        if( i != last ) {
            int points = task[day][i] + check( day - 1 , task , i ) ;  
            maxi = max( maxi , points ); 
        } 
    }

    return maxi ; 
} 

int check1(int day , vector<vector<int>> &task , int last , vector<vector<int>> &dp ) {
    if( day == 0 ) {
        int maxi = INT_MIN ; 
        for(int i=0 ; i<3 ; i++) {
            if( i != last ) {
                maxi = max( maxi , task[day][last] ) ; 
            }
        } 

        return maxi ; 
    }  

    if( dp[day][last] != -1 )  return dp[day][last] ; 

    int maxi = INT_MIN ; 

    for(int i=0 ; i<3 ; i++) {
        if( i != last ) {
            int points = task[day][i] + check1( day - 1 , task , i , dp ) ;  
            maxi = max( maxi , points ); 
        } 
    }

    return dp[day][last] = maxi ; 
} 

int check2(int day , vector<vector<int>> &task , int last , vector<vector<int>> &dp ) {
    // trying out tabulation 
    // bottom to top 

    int maxi = *max_element( task[0].begin() , task[0].end() ) ; 
    
    
}

int main(){

}