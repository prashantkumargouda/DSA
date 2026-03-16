#include <iostream>
#include <vector> 

using namespace std ; 

int main() {
    int t ; 
    cin >> t ; 

    while(t--){
        int n , m ;
        cin >> n >> m ; 

        vector<pair<int,int>> c ;  
        vector<pair<int,int>> s ; 

        for(int i=0 ; i<n ; i++){
            int a , b ; 
            cin >> a >> b ; 

            c.push_back({a,b}) ; 
        } 

        for(int i=0 ; i<m ; i++) {
            int a , b ;
            cin >> a >> b ; 

            s.push_back({a,b}) ;
        }  

        


    }
}