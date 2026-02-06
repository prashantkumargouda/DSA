// 130. Surrounded Regions
// Medium

// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

#include <iostream> 
#include <vector>
#include <queue> 

using namespace std ; 

void dfs(int row , int col , vector<vector<char>> &board , vector<vector<int>> &vis) {
    vis[row][col] = 1 ;  

    int rows = board.size() ; 
    int cols = board[0].size() ; 

    int delRow[] = {-1 , 0 , 1 , 0} ; 
    int delCol[] = {0 , 1 , 0 , -1} ; 

    for(int i=0 ; i<4 ; i++) {
        int nrow = row + delRow[i];  
        int ncol = col + delCol[i]; 

        if( nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
            dfs(nrow , ncol , board , vis) ; 
        }
    }
} 

void solve(vector<vector<char>> &board) {
    int row = board.size() ; 
    int col = board[0].size() ; 

    vector<vector<int>> vis( row , vector<int>(col , 0)) ; 

    for(int i=0 ; i<col ; i++) {
        if( !vis[0][i] && board[0][i] == 'O'){
            dfs( 0 , i , board , vis) ; 
        } 
        if( !vis[row - 1][i] && board[row - 1][i] == 'O' ) {
            dfs(row - 1, i , board , vis) ; 
        } 
    } 

    // we now check for values present in the first and last column  
    for(int i=0 ; i<row ; i++) {
        if( !vis[i][0] && board[i][0] == 'O' ) {
            dfs(i , 0, board , vis) ; 
        } 
        if( !vis[i][col -1] && board[i][col -1] ) {
            dfs(i , col - 1 , board , vis) ; 
        }
    } 

    for(int i=0 ; i<row ; i++) {
        for(int j=0 ; j<col ; j++) {
            if( !vis[i][j] && board[i][j] == 'O' ){
                board[i][j] = 'X' ; 
            }
        }
    } 
}
