#include <iostream>  
#include <vector> 
#include <algorithm> 
#include <unordered_map> 

using namespace std; 

// try to go from brute to best 

vector<int> twoSum(vector<int> &nums , int target) {
    int n = nums.size() ; 

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++) {
            if( nums[i] + nums[j] == target ) {
                return {i , j} ; 
            }
        }
    }  

    return {-1 ,-1} ; 
} 

vector<int> twoSum2(vector<int> &nums , int target){
    int n = nums.size() ; 

    // 2 6 5 8 11 
    // 2 5 6 8 11 

    vector<pair<int ,int>> numsIndex ; 

    for(int i=0 ; i<n ; i++) {
        numsIndex.push_back({nums[i] , i}) ; 
    } 
    
    sort(numsIndex.begin() , numsIndex.end()) ; 

    int left = 0 ; 
    int right = n-1 ; 

    sort( nums.begin() , nums.end() ) ; 

    while( left <= right ) { 
        int sum = numsIndex[left].first + numsIndex[right].first ; 

        if( sum < target ) {
            left++; 
        } 
        else if( sum > target ) {
            right++ ;
        } 
        else{
            return {numsIndex[left].second , numsIndex[right].second} ; 
        }
    } 

    return {-1 , -1} ; 
} 

vector<int> twoSum3(vector<int> &nums , int target) {
    int n = nums.size() ; 

    unordered_map<int ,int> mp ;  

    for(int i=0 ; i<n ;i++) {
        int complement = target - nums[i] ; 

        if( mp.find(complement) != mp.end() ) {
            return {mp[complement] , i} ;
        } 

        mp[nums[i]] = i ; 
    } 

    return {-1 , -1} ; 
} 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> nums(n) ; 
    for(auto &it : nums ) cin >> it ; 

    vector<int> temp = twoSum2(nums , 14) ; 

    for( auto &it : temp ) {
        cout << it << " " ;
    } 
    cout << endl; 

    return 0 ; 

}