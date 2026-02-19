// trying out topological sort using BFS 
// Kahn's Algorithm 

#include <iostream> 
#include <queue> 
#include <vector> 

using namespace std ;
 

vector<int> topoSort(int V , vector<vector<int>> &edges) {
    vector<vector<int>> adj(V) ; 

    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]) ; 
    } 

    vector<int> vis(V , 0) ; 
    
} 

int main(){

}