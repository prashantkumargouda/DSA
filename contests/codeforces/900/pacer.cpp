#include <bits/stdc++.h> 
using namespace std ; 

int main(){
    int t ; 
    cin >> t ; 

    while(t--) {
        long long n , m ;
        cin >> n >> m ; 

        vector<pair<int , int>> nums(n) ; 
        for(int i=0 ; i<n ; i++){
            cin >> nums[i].first >> nums[i].second ; 
        } 

        long long ans = 0 ; 

        int prevTime = 0 , prevSide = 0 ; 

        for(int i=0 ; i<n ; i++) {
            int sideDiff = abs( prevSide - nums[i].second ) ; 
            int gap = nums[i].first - prevTime ; 
            
            if( gap % 2 == sideDiff % 2 ) {
                ans += gap ; 
            } else {
                ans += gap - 1 ; 
            } 

            prevTime = nums[i].first ; 
            prevSide = nums[i].second ; 
        }   

        ans += m - prevTime ; 

        cout << ans << endl; 
    } 

    return 0 ; 
}