#include <iostream> 
#include <vector> 
#include <deque> 
#include <algorithm> 
#include <climits> 

using namespace std ;

int main(){
    int t ; 
    cin >> t ; 

    while(t--){
        int n,x,y ; 
        cin >> n >> x >> y ; 

        vector<int> p(n) ;  
        for(int &i:p) cin >> i ; 

        vector<int> pool ; 
        deque<int> mid ; 

        for(int i=0 ; i<x ; i++) pool.push_back(p[i]) ; 
        for(int i=y ; i<n ; i++) pool.push_back(p[i]) ; 

        for(int i=x ; i<y ; i++) mid.push_back(p[i]) ;  

        sort(pool.begin(),pool.end()) ; 

        int ptr = 0 ; 

        vector<int> ans ; 

        while( ans.size() < n ) {
            int bestPool = ( ptr < pool.size() ) ? pool[ptr] : INT_MAX ; 
            int bestMid = INT_MAX ; 

            if( !mid.empty() ) {
                bestMid = min( mid.front() , mid.back() ) ; 
            } 

            if( bestPool < bestMid ) {
                ans.push_back(bestPool) ; 
                ptr++ ; 
            } 
            else{
                if(mid.front() < mid.back()) {
                    ans.push_back(mid.front()) ; 
                    mid.pop_front() ; 
                } 
                else {
                    ans.push_back(mid.back()) ; 
                    mid.pop_back() ; 
                }
            }
        } 

        for(auto &it : ans){
            cout << it << " " ; 
        } 
        cout << endl; 
    } 
}