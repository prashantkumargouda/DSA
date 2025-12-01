//Duplicate within K Distance in an Array  
// Given an integer array arr[] and an integer k, determine whether there exist two indices i and j such that arr[i] == arr[j] and |i - j| ≤ k. If such a pair exists, return 'Yes', otherwise return 'No'. 

#include <iostream>  
#include <vector>  
#include <unordered_set> 
using namespace std ; 

// Naive Approach 
// bool checkDupeswithinK(vector<int> &arr , int k) {
//     int n = arr.size() ; 
//     //  naive approach 

//     for(int i=0 ; i<n ; i++) {
//         for(int c=1 ; c <= k && (i+c) <= n ; c++) {
//             int j = i+c ; 

//             if( arr[i] == arr[j] ) return true ; 
//         }
//     }
// } 

// Expected Approach 
bool checkDupeswithinK(vector<int> &arr , int k) {
    int n = arr.size() ; 

    unordered_set<int> hs ;  

    for(int i=0 ; i<n ; i++){
        if( hs.find(arr[i]) != hs.end() ) {
            return true ; 
        } 

        hs.insert(arr[i]) ;  // insert if not found 

        // then remove the elements which are not in the range 
        if( i>=k ) hs.erase(arr[i-k]) ; 
    }
    return false ; 
}

int main()
{
    vector<int> arr = {10, 5, 3, 4, 2, 1, 6};
    if (checkDupeswithinK(arr, 3))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}