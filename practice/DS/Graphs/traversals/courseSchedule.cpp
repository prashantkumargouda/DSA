// 207. Course Schedule
// Medium

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false. 

#include <iostream>  
#include <vector> 

using namespace std ; 

bool dfs(int node , vector<vector<int>> &adj , vector<int> &vis , vector<int> &pathVis) {
    vis[node] = 1 ; 
    pathVis[node] = 1 ; 

    for(auto it : adj[node]) {
        if( !vis[it] ) {
            if( !dfs(it , adj , vis , pathVis) ) {
                return false ; 
            } 
        } 
        else if(pathVis[it]) {
            return false ; 
        }
    } 
 
    pathVis[node] = 0 ; 
    return true ; 
} 

bool canFinish(int numCourses , vector<vector<int>> &preRequisites) {
    // provided the number of courses 
    // What I need to do is ? find if taking those courses is possible or not 
    // if there is a cycle it is not possible 

    int V = numCourses ; 

    vector<vector<int>> adj(numCourses)  ; 

    // adjacency list
    for(auto &e : preRequisites) {
        adj[e[0]].push_back(e[1]) ;
    }  

    vector<int> vis(V , 0) ; 
    vector<int> pathVis(V , 0) ; 


    for(int i=0 ; i<V ; i++) {
        if( !vis[i] ) {
            if(!dfs(i , adj , vis , pathVis)) {
                return false ;
            }
        }
    }  

    return true ; 
}  

int main() {
    int numCourses = 5 ;
    vector<vector<int>> preRequisites =  {{1,4},{2,4},{3,1},{3,2}} ; 

    if( canFinish(numCourses , preRequisites) ) {
        cout << "CHECK DONE" << endl;
    } 
    else{ 
        cout << "NO CHECK" << endl; 
    } 

    return 0 ; 
}