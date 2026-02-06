// 1020. Number of Enclaves
// Medium

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves. 

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 


void dfs(int row , int col , vector<vector<int>> &grid , vector<vector<int>> &vis) {
    vis[row][col] = 1 ; 

    int delRow[] = {-1 , 0 , 1 , 0} ; 
    int delCol[] = {0 , 1 , 0 , -1} ; 

    for(int i=0 ; i<4 ; i++) {
        int nrow = row + delRow[i] ; 
        int ncol = col + delCol[i] ; 

        if( nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ) {
            dfs(nrow , ncol , grid , vis) ; 
        }
    }
} 

int numEnclaves(vector<vector<int>> &grid) {
    int rows = grid.size() ; 
    int cols = grid[0].size() ; 

    int count = 0 ; 

    vector<vector<int>> vis(rows , vector<int>(cols ,0)) ; 

    for(int i=0 ; i<cols ; i++) {
        if( !vis[0][i] && grid[0][i] == 1 ) {
            dfs( 0 , i , grid , vis ) ; 
        }  
        if( !vis[rows - 1][i] && grid[rows-1][i] == 1 ) {
            dfs(rows - 1 , i , grid , vis ) ; 
        }
    } 

    for(int i=0 ; i<rows ; i++) {
        if( !vis[i][0] && grid[i][0] == 1 ) {
            dfs(i , 0 , grid , vis) ; 
        } 
        if( !vis[i][cols - 1] && grid[i][cols -1] == 1 ) {
            dfs(i , cols - 1 , grid , vis) ; 
        }
    } 

    for(int i=0 ; i<rows ; i++) {
        for(int j=0 ; j<cols ; j++){
            if( !vis[i][j] && grid[i][j] == 1 ) {
                count += 1 ; 
            }
        }
    } 

    return count ; 
} 

int main() {
    vector<vector<int>> grid = {{0,1,1,0}  , {0,0,1,0} , {0,0,1,0} , {0,0,0,0}} ; 

    cout<< numEnclaves(grid) << endl; 

    return 0 ; 
}