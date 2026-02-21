// 210. Course Schedule II
// Medium

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 
 
vector<int> findOrder(int numCourses , vector<vector<int>> &prerequisites) {
    int V = numCourses ; 

    vector<int> indegree(V,0) ;  
    vector<vector<int>> adj(V) ; 

    for(int i=0 ; i<V ; i++) {
        
    } 

    for(int i=0 ; i<V ; i++) {

    }
} 

int main() {

}