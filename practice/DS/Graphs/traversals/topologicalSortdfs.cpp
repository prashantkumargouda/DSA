// trying out topological sort  
// can only be applied to DAG : Directed Acyclic Graph 

#include <iostream> 
#include <stack> 
#include <vector> 

using namespace std ; 

void dfs(int node , vector<int> &vis , vector<vector<int>> &adj , stack<int> &st) {
    vis[node] = 1 ; 

    for(auto it : adj[node]) {
        if( !vis[it] ) dfs(it , vis , adj , st) ; 
    } 

    st.push(node) ; 
} 

vector<int> topoSort(int V , vector<vector<int>> &edges) {
    vector<vector<int>> adj(V)  ; 

    vector<int> vis(V ,0 ) ; 
    stack<int> st ; 

    for(int i=0 ; i<V ; i++) {
        if( !vis[i] ) {
            dfs(i , vis , adj ,  st ) ; 
        }
    }
    
    vector<int> ans ; 
    while( !st.empty() ) {
        ans.push_back(st.top()) ;  
        st.pop() ; 
    } 
    
    return ans ; 
    
} 

int main() {

}