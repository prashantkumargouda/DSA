// 2155. All Divisions With the Highest Score of a Binary Array
 
/* 
    You are given a 0-indexed binary array nums of length n. nums can be divided at index i (where 0 <= i <= n) into two arrays (possibly empty) numsleft and numsright:

numsleft has all the elements of nums between index 0 and i - 1 (inclusive), while numsright has all the elements of nums between index i and n - 1 (inclusive).
If i == 0, numsleft is empty, while numsright has all the elements of nums.
If i == n, numsleft has all the elements of nums, while numsright is empty.
The division score of an index i is the sum of the number of 0's in numsleft and the number of 1's in numsright.

Return all distinct indices that have the highest possible division score. You may return the answer in any order.

*/

#include <bits/stdc++.h> 
using namespace std ; 

vector<int> maxScoreIndices(vector<int> &nums) {
    unordered_map<int , int> mp ; 
    int n = nums.size() ; 

    int maxi = INT_MIN ; 

    for(int i=0 ; i<=n ; i++){ 
        int j = 0 ;
        
        int count0 = 0; 
        int count1 = 0; 
        while( j < i ) {
            if(nums[j++] == 0) {
                count0++ ;
            }
        } 
        while( j<n ) {
            if( nums[j++] == 1) {
                count1++ ;
            }
        }
        
        mp[i] = count0 + count1 ; 
        maxi = max( maxi , mp[i]) ;
    }  

    vector<int> ans ; 
    for(auto &it : mp) {
        if( it.second == maxi ) {
            ans.push_back(it.first) ; 
        }
    } 

    return ans ; 
} 

vector<int> maxScoreIndices(vector<int> &nums) {
    int n = nums.size() ; 

    vector<int> prefix( n+1 , 0 ) ; 
    vector<int> suffix( n+1 , 0 ) ; 

    int count0 = 0 ; 
    int count1 = 0 ;

    prefix[0] = 0 ; 

    for(int i=1 ; i<=n ; i++){
        if( nums[i-1] == 0 ) {
            count0 += 1 ; 
        }
        prefix[i] = count0 ; 
    } 

    suffix[n] = 0 ; 

    for(int i=n-1 ; i>=0 ; i--){
        if( nums[i] == 1 ) {
            count1 += 1 ; 
        } 
        suffix[i] = count1 ; 
    } 

    vector<int> ans ; 
    int maxi = INT_MIN ; 

    for(int i=0 ; i<n ; i++){
        maxi = max( maxi , prefix[i] + suffix[i] ) ; 
    }  

    for(int i=0 ; i<n ; i++) {
        if( suffix[i] + prefix[i] == maxi ) {
            ans.push_back(i) ; 
        }
    } 

    return ans ; 
}

vector<int> maxScoreIndices(vector<int> &nums){
    int n = nums.size() ; 
    
    int leftZeros = 0 ; 
    int rightOnes = 0 ; 

    for(int x : nums) {
        if( x == 1 ) rightOnes++ ; 
    } 

    int maxi = rightOnes ; 
    vector<int> ans = {0} ; 

    for(int i=0 ; i<n ; i++){ 
        if( nums[i] == 0 ) {
            leftZeros++ ; 
        } 
        else rightOnes-- ; 

        int sum = leftZeros + rightOnes ;  

        if( sum > maxi ) {
            ans = {i+1} ; 
            maxi = sum ; 
        }  
        else if( sum == maxi ) {
            ans.push_back(i+1) ; 
        }
    } 

    return ans ; 

}