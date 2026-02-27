// trying out dijkstras algo for shortest path using sets 

#include <iostream> 
#include <vector> 
#include <set> 

using namespace std ; 

vector<int> shortestPath(int V , vector<vector<int>> &edges , int src) {
    // using a fuckin' set 
    // which gives you the liberty of deleting a node when a better one arrives 
    // instead of the way it acts in a priority_queue 

    set<pair<int , int>> st ;   
    vector<int> dis(V , INT_MAX) ; 

    vector<vector<pair<int , int>>> adj(V) ; 
    for(auto &e : edges) {
        int u = e[0] ; 
        int v = e[1] ; 
        int wt = e[2] ; 

        adj[u].push_back({v , wt}) ; 
        adj[v].push_back({u , wt}) ; 
    } 

    dis[src] = 0 ;  
    st.insert({ 0 , src}) ; 

    while( !st.empty() ) {
        auto it = *(st.begin()) ; 
        int node = it.second ; 
        int dist = it.first ; 

        for(auto it : adj[node]) {
            int v = it.first ; 
            int wt = it.second ; 

            if( dist + wt < dis[v] ) {
                if( dis[v] != INT_MAX ) {
                    st.erase({dis[v] , v}) ;    
                } 
                dis[v] = dist + wt ; 
                st.insert({ dis[v] , v }) ; 
            }
        }
    } 

    return dis ; 
} 

int main() {

}