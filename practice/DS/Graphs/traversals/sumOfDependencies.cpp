#include <iostream> 
#include <vector> 

using namespace std ; 

int sum(int V , vector<vector<int>> &edges) {
    int sum = 0; 

    vector<vector<int>> adj(V) ; 

    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]) ; 
    } 

    for(int i=0 ; i<V ; i++){
        sum += adj[i].size() ; 
    } 
    
    return sum ; 
} 

int main() {

}