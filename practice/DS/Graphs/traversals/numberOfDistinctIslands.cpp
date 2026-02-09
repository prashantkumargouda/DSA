// finding the number of distinct islands 

#include <iostream> 
#include <vector> 
#include <set> 

using namespace std ; 

void dfs(int row , int col , vector<vector<int>> &grid , vector<vector<int>> &vis ,vector<pair<int , int>> &vec ,int row0 , int col0 ){
    vis[row][col] = 1 ; 

    vec.push_back({row - row0 , col - col0}) ; 
    
    int rows = grid.size() ; 
    int cols = grid[0].size() ; 

    int delRow[] = {-1 ,0 , 1 ,0} ; 
    int delCol[] = {0 , 1 , 0 , -1} ; 

    for(int i=0 ; i<4 ; i++) {
        int nrow = row + delRow[i] ; 
        int ncol = col + delCol[i] ; 

        if( nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ) {
            dfs(nrow , ncol , grid , vis , vec , row0 , col0 ) ; 
        }
    }
} 

int distinctCounts(vector<vector<int>> &grid) {
    int rows = grid.size() ; 
    int cols = grid[0].size() ; 

    vector<vector<int>> vis(rows , vector<int>( cols , 0)) ; 
    set<vector<pair<int , int>>> st ; 

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if( !vis[i][j] && grid[i][j] ==1 ) {
                vector<pair<int , int>> vec ; 
                dfs(i , j , grid , vis , vec , i , j ) ; 
                st.insert(vec) ; 
            }
        }
    } 

    return st.size() ; 
}
int main() { 
    vector<vector<int>> temp = {{1,1,0,1,1} , {1,0,0,0,0} , {0,0,0,0,1} , {1,1,0,1,1} } ; 
    int check = distinctCounts(temp) ; 

    cout << check << endl; 

    return 0 ;
}