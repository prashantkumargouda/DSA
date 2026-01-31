// 200. Number of Islands
// Medium
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 

void bfs(int row , int col , vector<vector<char>> &grid , vector<vector<int>> &vis) { 
    // marked as visited  
    vis[row][col] = 1 ;  

    queue<pair<int,int>> q ; 
    q.push({row , col}) ; 

    int n = grid.size() ; 
    int m = grid[0].size() ; 

    for(int i=-1 ; i<=1 ; i++) {
        for(int j=-1 ; j<=1 ; j++) {
            
        }
    }


}

int noOfIslands(vector<vector<char>> &grid) {
    int rows = grid.size() ; 
    int cols = grid[0].size() ; 

    int count = 0 ; 
    vector<vector<int>> vis(rows , vector<int>(cols , 0)) ; 

    for(int i=0 ; i<rows ; i++) {
        for(int j=0 ; j<cols ; j++) {
            if( !vis[i][j] ) {
                bfs() ;
                count++ ;
            }
        }
    }
} 

int main() {

}