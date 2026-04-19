// 2169A  

#include <bits/stdc++.h> 
using namespace std ; 

int main() {
    int t ; 
    cin >> t ; 

    while(t--) { 
        int n ; 
        long long a ; 
        cin >> n >> a ; 

        vector<long long> nums(n) ; 
        for(auto &it : nums) cin >>  it ;   

        int L = lower_bound(nums.begin() , nums.end() , a) - nums.begin() ;  
        int R = n - (upper_bound(nums.begin() , nums.end() , a) - nums.begin()) ;   

        if( L > R ) {
            cout << a - 1 << endl; 
        } 
        else {
            cout << a + 1 << endl; 
        }
    } 

    return 0 ; 
}