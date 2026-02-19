#include <iostream> 
#include <vector> 
#include <set> 

using namespace std ; 

int main() {
    int t ; 
    cin >> t ; 

    while( t-- ) {
        int n ; 
        cin >> n ; 

        vector<int> arr(n+1) ; 

        for(int i=1 ; i<=n ; i++) {
            cin >> arr[i] ; 
        } 

        bool check = false ; 

        for(int i=1 ; i<=n ; i++) {
            if( i%2 == 1 ) { // if the value is odd 
                vector<int> chains ; 
                for(int j=i ; j<=n ; j*=2) {
                    chains.push_back(j) ; 
                } 

                multiset<int> vals , idxs ;  

                for(auto it : chains){
                    vals.insert(it) ;
                    idxs.insert(it) ;     
                }  

                if( vals != idxs ){
                    check = false ;
                }
            }
        } 

        check == true ? cout << "YES" : cout << "NO" ;  

        cout << endl; 
    } 

    return 0 ; 
}