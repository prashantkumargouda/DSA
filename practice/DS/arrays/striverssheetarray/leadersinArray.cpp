// finding the leaders present in an array 

#include <iostream> 
#include <vector> 
#include <climits> 

using namespace std ; 

vector<int> leaders(vector<int> &nums) {
    int n = nums.size() ; 
    vector<int> ans; 

    if(nums.empty()){
        return ans ; 
    } 
    
    int maxi = INT_MIN ;  

    for(int i=n-1 ; i>=0 ; i--) {
        if( nums[i] > maxi ) {
            maxi = nums[i] ;  
            ans.push_back(maxi) ; 
        } 
    } 
    reverse(ans.begin() , ans.end()) ; 

    return ans ;  

    // 1 2 5 3 1 2 
    // 2 3 5  
    // 5 3 2  
    
    // -3 4 5 1 -4 -5 
} 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ; 

    vector<int> temp = leaders(nums) ; 

    for(auto it : temp){
        cout << it << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}