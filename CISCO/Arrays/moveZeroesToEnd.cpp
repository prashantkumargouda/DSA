#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

// move zeros to the end 

vector<int> solve(vector<int> nums) {
    int n = nums.size() ; 
    int index = 0 ; 

    for(int i=0 ; i<n ; i++){
        if( nums[i] == 0 ) {
            index = i ;  
            break ; 
        }
    }
    
    for(int i=index+1 ; i<n ; i++) {
        if(nums[i] != 0 ) {
            swap(nums[i] , nums[index]) ;  
            index++ ; 
        }
    }

    return nums ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1,1,0,2,0,0,3} ; 
    vector<int> temp = solve(nums)  ; 

    for(int x: temp) {
        cout << x << " " ; 
    }
    return 0;
}