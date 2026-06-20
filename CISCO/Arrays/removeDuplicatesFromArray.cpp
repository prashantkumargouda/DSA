// removing the duplicate elements from an array 

#include <bits/stdc++.h> 
using namespace std ; 

int removeDupes(vector<int> &arr) {
    int n = arr.size() ;

    unordered_set<int> seen ; 

    int index = 0 ; 
    for(int num : arr) {
        if( seen.find(num) == seen.end() ){
            seen.insert(num) ; 
            arr[index++] = num ;
        }
    }   

    return index ; 
} 

int removeDupes2(vector<int> &arr) {
    int index = 1 ; 
    int n = arr.size() ; 

    for(int i=1 ; i<n; i++) {
        if( arr[i] != arr[i-1] ) {
            arr[index++] = arr[i] ; 
        }
    } 

    return index ; 
}