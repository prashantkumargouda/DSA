// 200. Number of Islands
// Medium
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 

void bfs(int row , int col , vector<vector<char>> &grid , vector<vector<int>> &vis) {
    vis[row][col] = 1 ; 
    queue<pair<int , int>> q  ; 

    int rows = grid.size() ; 
    int cols = grid[0].size() ; 

    q.push({row , col}) ; 
    while(!q.empty()) {
        int row = q.front().first ; 
        int col = q.front().second ; 

        q.pop() ; 

        for(int delrow = -1 ; delrow <= 1 ; delrow++) {
            for(int delcol = -1 ; delcol <= 1 ; delcol++) {
                int nrow = row + delrow ; 
                int ncol = col + delcol ;  
                
                if( row >= 0 && col >= 0 && row < rows && col < cols && grid[nrow][ncol] == 1 & !vis[nrow][ncol] ) {
                    // if all cases satisfied 
                    vis[row][col] = 1 ; 
                    q.push({row , col}) ;                                                               
                }
            }
        }
    }
} 

int noOfIslands(vector<vector<char>> &grid) {
    int row = grid.size() ; 
    int col = grid[0].size() ; 

    int count = 0 ; 

    vector<vector<int>> vis( row , vector<int> (col , 0)) ; 

    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            if( !vis[i][j] ) {
                bfs(i,j,grid,vis) ; 
                count++ ;
            }
        }
    }
} 

int main() {

}