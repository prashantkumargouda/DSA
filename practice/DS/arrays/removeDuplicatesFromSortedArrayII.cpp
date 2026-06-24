// REMOVE DUPLICATES FROM SORTED ARRAY II 

#include <bits/stdc++.h> 
using namespace std ; 

// TC - O(n) 
// SC - O(1) 

int removeDuplicates(vector<int> &nums) {
    int n = nums.size() ; 

    if( n <= 2 ) return 2 ; 

    int k=2 ; 

    for(int i=2 ; i<n ; i++) {
        if( nums[i] != nums[k-2] ) {
            nums[k] = nums[i] ;  
            k++ ; 
        }
    } 

    return k ; 
}