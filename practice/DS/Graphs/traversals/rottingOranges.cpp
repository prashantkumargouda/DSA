// 994. Rotting Oranges
// Medium
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 
#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ;

void bfs(int row , int col , vector<vector<int>> &grid , vector<vector<int>> &vis) {
    vis[row][col] = 1 ; 
    
} 

int orangesRotting(vector<vector<int>> &grid) {
    int row = grid.size() ; 
    int col = grid[0].size() ; 

    vector<vector<int>> vis( row , vector<int>(col , 0)) ; 

    int min = 0 ; 

    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            if( !vis[i][j] ) {
                bfs(i, j , grid, vis)  ;
            }
        }
    } 

    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            if( vis[row][col] == 1 && !vis[row][col] )  {
                return -1 ; 
            }
        }
    } 

    return min ; 
} 

int main() {

}