// DNA Sequence 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

vector<string> solve(string s) {
    unordered_map<string , int> mp ; 
    vector<string> ans ; 

    for(int i=0 ; i+9 < s.size() ; i++){
        string str = s.substr(i,10) ; 

        mp[str]++ ; 
        if( mp[str] == 2 ) {
            ans.push_back(str) ;
        }
    } 

    return ans ; 
}

vector<string> solve1(string s) {
    unordered_map<string , int> mp ; 
    vector<string> ans ; 
    
    int n = s.size() ; 

    int left = 0 ; 
    for(int right = 0 ; right < n ; right++) {
        if( right - left + 1 == 10 ) {
            string str = s.substr(left , 10)  ;  
            mp[str]++ ; 

            if(mp[str] == 2) ans.push_back(str) ; 
        }
    } 
    return ans ; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT" ;  
    vector<string> temp = solve(s) ; 
    for(string str : temp) {
        cout << str << " " ; 
    } 

    return 0;
}