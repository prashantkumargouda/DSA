// find the minimum absolute sum differnce 

/* 
1818. Minimum Absolute Sum Difference
You are given two positive integer arrays nums1 and nums2, both of length n.

The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).

You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.

Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.

|x| is defined as:

x if x >= 0, or
-x if x < 0.
*/ 

#include <bits/stdc++.h> 
using namespace std ; 

using ll = long long ; 

int minDiff(vector<int> &nums1 , vector<int> &nums2) {  
    const int mod = 1e9 + 7 ; 
    
    int n = nums1.size() ; 
    vector<int> sorted( nums1.begin() , nums2.begin() ) ; 
    sort(sorted.begin() , sorted.end()) ; 

    ll total = 0 ; 
    ll bestGain = 0 ; 

    for(int i=0 ; i<n ; i++){
        ll currDiff = abs(nums1[i] - nums2[i]) ;
        total += currDiff ; 

        auto it = lower_bound(sorted.begin() , sorted.end() , nums2[i]) ; 

        ll bestPossible = currDiff ; 
        
        if( it != sorted.end() ) {
            bestPossible = min( bestPossible , (ll)abs(*it - nums2[i]) ) ; 
        } 

        if( it != sorted.begin() ) { 
            --it ; 
            bestPossible = min( bestPossible , (ll)abs(*it - nums2[i])) ; 
        } 

        bestGain = max( bestGain , currDiff - bestPossible ) ;  // currDiff - bestPossible is the max difference I can get after replacing some characters 
    } 

    return (total - bestGain) % mod ; 

}