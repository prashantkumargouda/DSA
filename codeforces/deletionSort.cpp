// AksLolCoding is playing a game on an array a
//  of n
//  positive integers. During each turn:

// If a
//  is non-decreasing∗
// , the game ends.
// Otherwise, AksLolCoding can choose any single element and remove it from the array.
// Determine the minimum possible number of elements that can be remaining in the array after the game ends.

// ∗
// a
//  is non-decreasing if ai≤ai+1
//  for all 1≤i≤m−1
// , where m
//  is the length of a
// .

// Input
// The first line contains an integer t
//  (1≤t≤1000
// ), the number of test cases.

// The first line of each test case contains an integer n
//  (1≤n≤10
// ).

// The second line of each test case contains n
//  integers, the elements of a
//  (1≤ai≤100
// ).

// Output
// For each test case, output an integer: the minimum possible number of elements left once the array is sorted. 


// AksLolCoding is playing a game on an array a
//  of n
//  positive integers. During each turn:

// If a
//  is non-decreasing∗
// , the game ends.
// Otherwise, AksLolCoding can choose any single element and remove it from the array.
// Determine the minimum possible number of elements that can be remaining in the array after the game ends.

// ∗
// a
//  is non-decreasing if ai≤ai+1
//  for all 1≤i≤m−1
// , where m
//  is the length of a
// .

// Input
// The first line contains an integer t
//  (1≤t≤1000
// ), the number of test cases.

// The first line of each test case contains an integer n
//  (1≤n≤10
// ).

// The second line of each test case contains n
//  integers, the elements of a
//  (1≤ai≤100
// ).

// Output
// For each test case, output an integer: the minimum possible number of elements left once the array is sorted. 

#include <iostream>  
#include <vector> 
#include <algorithm> 

using namespace std ;

int main(){
    int t ;  
    cin >> t ; 

    while( t-- ) {
        int n ; 
        cin >> n ; 

        vector<int> arr(n) ; 

        for(int i=0 ; i<n ; i++) {
            cin >> arr[i] ;  
        } 

        if( is_sorted(arr.begin() , arr.end())) {
            cout << arr.size() << endl ;
        } 
        else{
            cout << 1 << endl; 
        }
    } 

    return 0 ; 

}