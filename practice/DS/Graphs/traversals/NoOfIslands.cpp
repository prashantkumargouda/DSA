// 200. Number of Islands
// Medium
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ;
 
void bfs(int row , int col , vector<vector<char>> &grid , vector<vector<int>> &vis ) {
    vis[row][col] = 1 ; 

    queue<pair<int , int>> q ; 
    q.push({row , col}) ; 

    vector<int> delRow = {-1 , 0 , 1 , 0} ;  
    vector<int> delCol = {0 , 1 , 0 , -1} ; 

    int rows = grid.size() ; 
    int cols = grid[0].size() ; 

    while( !q.empty() ) {
        int r = q.front().first ; 
        int c = q.front().second ; 

        for(int i=0 ; i<4 ; i++) {
            int nrow = r + delRow[i] ; 
            int ncol = c + delCol[i] ;  

            if( nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ) {
                vis[nrow][ncol] = 1 ; 
                q.push({nrow , ncol}) ; 
            } 
        }
    } 
} 

int noOfIslands(vector<vector<char>> &grid) {
    int row = grid.size() ;     
    int col = grid[0].size() ; 

    vector<vector<int>> vis(row , vector<int>(col , 0)) ; 
    
    int count = 0 ; 

    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            if( !vis[i][j] && vis[i][j] == 1 ) {
                bfs(i ,  j , grid , vis) ; 
                count++ ; 
            }
        }
    } 

    return count ; 
} 

int main() {
    
}