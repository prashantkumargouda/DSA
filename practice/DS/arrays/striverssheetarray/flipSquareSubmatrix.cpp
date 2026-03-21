// learnt how to flip a matrix or submatrix vertically 

#include <iostream>  
#include <vector> 
using namespace std ;  

vector<vector<int>> reverseSubMatrix(vector<vector<int>> &grid , int x ,int y , int k ) {
    int n = grid.size() ; 
    int m = grid[0].size() ; 

    for(int i=x ; i<x+k/2 ; i++) {
        for(int j=y ; j<y+k ; j++){
            swap( grid[i][j] , grid[2*x + k - 1 - i][j] ) ; 
        }
    } 

    return grid ; 
} 

int main() {
    int n , m ; 
    cin >> n >> m ; 

    vector<vector<int>> mat(n , vector<int>(m))  ; 

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> mat[i][j] ; 
        }
    } 

    // print the same nums 2d matrix  
    
    return 0 ; 
}