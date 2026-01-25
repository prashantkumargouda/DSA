// Representation of a graph in c++  
// input
// you will be always provided with n and m 
// n nodes and m edges 
 
// after taking inputs the second thing to keep in mind is 
// storing the values for which there is 
// 1. matrix way  and 2. List way 

// trying out the matrix way using an adjacency matrix 

#include <iostream>  
#include <vector> 

using namespace std ; 

// the input will be in the form of 
// 5 6 
// 2 1 
// 3 1 
// 3 4 
// 4 5 
// 2 5 
// 2 4 

// int main() {
//     int n , m ; 
//     cin >> n >> m ; 

//     vector<vector<int>> adj(n+1 , vector<int>(n+1 , 0)) ; 
    
//     // based on the number of edges 
//     // take the input for the edges 

//     for(int i=0 ; i<m ; i++) {
//         int u , v ; 
//         cin >> u >> v ; 

//         adj[u][v] = 1 ; 
//         adj[v][u] = 1 ; 
//     }
    
//     return 0 ; 
// } 

// now using an adjacency list to store the graph elements for an undirected graph 

// int main() { 
//     int n , m ; 
//     cin >> n >> m ;

//     vector<vector<int>> adj(n+1) ;      

//     for(int i=0 ; i<m ; i++) {
//         int u , v ; 
//         cin >> u >> v ; 

//         adj[u].push_back(v) ; 
//         adj[v].push_back(u) ;
//     } 

//     return 0 ; 
// } 

