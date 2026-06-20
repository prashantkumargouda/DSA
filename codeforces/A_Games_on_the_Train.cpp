#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

int solve(vector<int> nums) {
    int n = nums.size() ; 

    int maxi = *max_element(nums.begin() , nums.end()) ; 
    int mini = *min_element(nums.begin() , nums.end()) ; 

    return (maxi + 1 - mini) ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ; 
    cin >> t ; 

    while (t--) {
        int n ; 
        cin >> n ; 

        vector<int> nums(n) ; 
        for(auto &it : nums) {
            cin >> it ; 
        } 

        cout << solve(nums) << endl;
    }

    return 0;
}