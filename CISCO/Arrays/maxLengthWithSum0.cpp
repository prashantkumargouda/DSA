// find the maximum lenght of subarray with sum 0 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

int solve(vector<int> &nums){
    int n = nums.size() ; 

    int maxLen=0 ; 
    int sum = 0 ; 

    unordered_map<int , int> mp ; 
    for(int i=0 ; i<n ; i++) {
        sum += nums[i] ; 

        if( sum == 0 ) {
            maxLen = max(maxLen , i+1) ; 
        } 
        else if( mp.find(sum) != mp.end() ) {
            maxLen = max(maxLen , i - mp[sum]) ; 
        } 
        else{
            mp[sum] = i ; 
        }
    } 
    return maxLen ; 
} 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}