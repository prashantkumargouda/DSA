#include <iostream> 
#include <vector> 
#include <deque> 

using namespace std ; 

int main() {
    int t ; 
    cin >> t ; 
    
    while(t--) {
        int n , x , y ; 
        cin >> n >> x >> y ;  

        vector<int> p(n) ; 

        for(auto &it : p) cin >> it  ;  

        vector<int> pool ; 
        deque<int> mid ; 

        for(int i=0 ; i<x ; i++) pool.push_back(p[i]) ;
    }
}

