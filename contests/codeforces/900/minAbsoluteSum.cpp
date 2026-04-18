// finding the lexicographically smallest array 
// which contains absolute sum of elements in diff array to be minimum 

#include <bits/stdc++.h> 
using namespace std ;

vector<int> check(vector<int> &nums) {     
    int n = nums.size() ;
    if( nums[0] != -1 && nums[n-1] == -1 ) {
        nums[n-1] = nums[0] ; 
    }   
    else if( nums[0] == -1 && nums[n-1] != -1 ) {
        nums[0] = nums[n-1] ; 
    } 

    for(int i=0 ; i<n  ; i++){
        if( nums[i] == -1 ) {
            nums[i] = 0 ;
        }
    }

    return nums ; 
} 

int main() {
    int t ; 
    cin >> t ; 

    while( t-- ) {
        int n ;
        cin >> n ; 

        vector<int> nums(n) ; 
        for(auto &it : nums) cin >> it ;  

        vector<int> temp = check(nums)  ; 

        cout << abs(temp[n-1] - temp[0]) << endl; 
        for(int i=0 ; i<n ; i++) {
            cout << temp[i] << " " ; 
        } 

        cout << endl; 
    } 

    return 0 ; 
}