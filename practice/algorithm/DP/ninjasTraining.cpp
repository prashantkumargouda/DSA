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
                maxi = max( maxi , task[day][i] ) ; 
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

// tabulation solution 
int ninjaTraining1(int n, vector<vector<int>> &points)
{
    // trying out tabulation 
    vector<vector<int>> dp( n , vector<int>( 4 , 0 )) ; 
    
    dp[0][0] = max( points[0][1] , points[0][2] ) ;  
    dp[0][1] = max( points[0][0] , points[0][2] ) ; 
    dp[0][2] = max( points[0][1] , points[0][0] ) ;  
    dp[0][3] = max( points[0][1] , max( points[0][0] , points[0][2] )  ) ;  

    for(int day = 1 ; day < n ; day++) {
        for(int last = 0 ; last < 4 ; last++ ) {
            dp[day][last] = 0 ; 
            for(int task = 0 ; task < 3 ; task++) { 
                if( task != last ) {
                    int check = points[day][task] + dp[day-1][task] ;  
                    dp[day][last] = max( dp[day][last] , check ) ; 
                }
            }
        }
    } 

    return dp[n-1][3] ;
}

// space optimization 
int ninjaTraining2(int n, vector<vector<int>> &points)
{
    // trying out tabulation 
    vector<int> prev(4 , 0) ;  
    
    prev[0] = max( points[0][1] , points[0][2] ) ;  
    prev[1] = max( points[0][0] , points[0][2] ) ; 
    prev[2] = max( points[0][1] , points[0][0] ) ;  
    prev[3] = max( points[0][1] , max( points[0][0] , points[0][2] ) ) ;  

    for(int day = 1 ; day < n ; day++) { 
        vector<int> temp(4,0) ; 
        for(int last = 0 ; last < 4 ; last++ ) { 
            for(int task = 0 ; task < 3 ; task++) { 
                if( task != last ) {
                    int check = points[day][task] + prev[task] ;  
                    temp[last] = max( temp[last] , check ) ; 
                } 
            } 
        }
        prev = temp ; 
    } 

    return prev[3] ;
}

int main(){
    
}