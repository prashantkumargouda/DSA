// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. 

#include <iostream>  
#include <vector>

using namespace std ; 

void solve(vector<vector<int>> &matrix) {
    int m = matrix.size() ; 
    int n = matrix[0].size() ; 

    vector<int> col(n , 0) ; 
    vector<int> row(m , 0) ; 

    for(int i=0 ; i<m ; i++) {
        for( int j=0 ; j<n ; j++) {
            if( matrix[i][j] == 0 ) {
                col[j] = 1 ; 
                row[i] = 1 ; 
            }
        }
    } 


    for(int i=0 ; i<m ; i++) {
        for(int j=0 ; j<n ; j++) {
            if( col[j] == 1 || col[i] == 1 ){
                matrix[i][j] = 0 ;
            }
        }
    }  
} 

int main() {
    int m,n ;  
    cin >> m >> n ; 

    vector<vector<int>> matrix( m , vector<int>(n) ) ; 

    
    
}