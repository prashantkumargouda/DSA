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

void solve(vector<vector<char>> &board){
    int row = board.size() ; 
    int col = board[0].size() ; 

    vector<vector<int>> vis(row , vector<int>(col ,0)) ; 

    // going through the 2 rows and 2 columns 
    // here comes the first row 
    for(int j=0 ; j<col ; j++) {
        if( !vis[0][j] && board[0][j] == '0' ) {
            vis[0][j] = 1 ; 
        }
    }
}

int main() {

}