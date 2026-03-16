// There are n
//  players playing a game at a circular table. The i
// -th player has ai
//  dishes to eat. They take turns eating the food, and any player can go first.

// During their turn, if player i
//  has any dishes remaining, they must eat exactly one dish. Then, player (imodn)+1
//  starts their turn. This continues until all dishes are finished.

// The player who eats the last dish is considered the winner. Determine the number of players that can possibly be winners.

// Input
// The first line contains an integer t
//  (1≤t≤5000
// ), the number of test cases.

// The first line of each test case contains an integer n
//  (1≤n≤10
// ).

// The second line of each test case contains n
//  integers, the elements of a
//  (1≤ai≤10
// ).

// Output
// For each test case, output a line with the answer. 

#include <iostream>  
#include <vector> 
#include <climits> 

using namespace std ;

int main(){
    int t ; 
    cin >> t ; 

    while(t--) {
        int n ; 
        cin >> n ; 

        vector<int> arr(n) ;  
        int maxi = INT_MIN ; 

        vector<int> maximums ; 

        for(int i=0 ; i<n ; i++){
            cin >> arr[i] ;
            maxi = max( maxi , arr[i] ) ; 
        }  

        int count = 0 ; 

        for( auto x : arr ) {
            if( x == maxi ) count++ ; 
        }
        
        cout << count << endl; 
        
    } 

    return 0 ; 
}