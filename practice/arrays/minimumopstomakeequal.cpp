// You are given an array of n-elements,
//you have to find the number of operations needed to make all elements of array equal.
// Where a single operation can increment an element by k.
// If it is not possible to make all elements equal print -1. 

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std ;

int minOperations(vector<int> &arr , int k) {
    int n = arr.size() ; 
    int maxValue = *max_element(arr.begin(), arr.end()) ;   

    int res = 0 ; 
    for(int x : arr) { 
        if((maxValue - x) % k  != 0 ) return -1 ; 

        res += (maxValue - x) / k ; 
    }
    return res ; 
} 

int main() { 
    vector<int> arr = {4, 4, 4, 4} ; 
    int k = 3 ; 

    cout << minOperations(arr , k) << endl; 

    return 0 ; 

}