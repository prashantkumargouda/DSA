// 787. Cheapest Flights Within K Stops
// Medium
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1. 

#include <iostream>
#include <vector> 
#include <queue> 

using namespace std ; 

int findCheapestPrice(int V , vector<vector<int>> &flights , int src , int dst , int k ) {
    // here I need a queue which stores the steps , dist ,and the node 

    queue<pair<int , pair<int , int>>> q ;
    vector<int> dis(V , INT_MAX) ;  

    vector<vector<pair<int , int>>> adj(V) ; 
     
    for(auto &e : flights) {
        int u = e[0] ; 
        int v = e[1] ; 
        int wt = e[2] ; 

        adj[u].push_back( {v , wt} ) ; 
    } 

    dis[src] = 0 ;  
    q.push({ 0 , {0 , src}}) ;  

    while( !q.empty() ) { 
        int steps = q.front().first ; 
        int node = q.front().second.second ; 
        int dist = q.front().second.first ; 
        
        q.pop() ;

        if( steps > k ) continue ; 

        for(auto &it : adj[node]) {
            int v = it.first ; 
            int wt = it.second ; 

            if( dist + wt < dis[v] ) {
                dis[v] = dist + wt ;  
                q.push({steps + 1 , {dis[v] , v}}) ; 
            }
        }
    } 

    if( dis[dst] == INT_MAX ) return -1 ; 
    
    return dis[dst] ; 
} 

int main() { 

}