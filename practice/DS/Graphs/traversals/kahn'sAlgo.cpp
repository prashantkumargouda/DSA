// Kahn's Algorithm 
// topological sort using bfs 

#include <iostream>  
#include <vector> 
#include <queue> 

using namespace std ; 

vector<int> kahns(int V , vector<vector<int>> &edges) { 
    vector<vector<int>> adj(V) ; 
    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]) ; 
    }  

    // iske baad create the indegree vector 

    vector<int> indegree(V , 0) ; 

    for(int i=0 ; i<V ; i++ ){
        for(auto it : adj[i]) {
            indegree[it]++ ; 
        }
    }   

    queue<int> q ; 

    for(int i=0 ; i<V ; i++ ) {
        if(indegree[i] == 0 ) {
            q.push(i) ; 
        }
    } 

    vector<int> ans ; 
    while( !q.empty() ) {
        int node = q.front() ; 
        q.pop() ; 
        ans.push_back(node) ;

        // okay so now 
        // as I remove the elements from the queue I add those into the ans 
        // visit the adjacent nodes 

        for(auto it : adj[node]) {
            indegree[it]-- ; 
            if(indegree[it] == 0){
                q.push(it) ; 
            }
        } 
    }

    return ans ; 

} 

int main() {

}