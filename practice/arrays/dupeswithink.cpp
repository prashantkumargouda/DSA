//Duplicate within K Distance in an Array  
// Given an integer array arr[] and an integer k, determine whether there exist two indices i and j such that arr[i] == arr[j] and |i - j| ≤ k. If such a pair exists, return 'Yes', otherwise return 'No'. 

#include <iostream>  
#include <vector> 
using namespace std ; 

bool checkDupeswithinK(vector<int> &arr , int k) {
    int n = arr.size() ; 
    //  naive approach 

    for(int i=0 ; i<n ; i++) {
        for(int c=1 ; c <= k && (i+c) <= n ; c++) {
            int j = i+c ; 

            if( arr[i] == arr[j] ) return true ; 
        }
    }
} 

int main()
{
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    if (checkDupeswithinK(arr, 3))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}