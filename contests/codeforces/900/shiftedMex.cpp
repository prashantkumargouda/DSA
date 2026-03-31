#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <climits> 
#include <set> 

using namespace std ; 

int compute(vector<int> &nums ,int shift) {
    int n = nums.size() ; 

    set<int> s ; 
    for(int num : nums) {
        s.insert( num + shift ) ;  
    } 

    int mex = 0 ; 
    while( s.count(mex) ) { 
        mex++ ; 
    } 

    return mex ; 

} 

int check(vector<int> &nums) {
    int n = nums.size() ; 
    
    int ans = 0 ; 
    for(int num : nums) {
        int shift = -num ; 
        ans = max( ans , compute(nums , shift)) ; 
    } 
    
    return ans ; 
}

int main() { 
    int t ; 
    cin >> t ; 
    while(t--) {
        int n ; 
        cin >> n ; 

        vector<int> nums(n);
        for(auto &it : nums) cin >> it ; 

        cout << check(nums) << endl;  
    }

    return 0 ;  
}