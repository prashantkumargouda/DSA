// rotating a matrix by 90 

#include <iostream> 
#include <vector> 

using namespace std ;  

void rotate1(vector<vector<int>> mat){
    int n = mat.size() ; 
    int m = mat[0].size() ; 

    vector<vector<int>> ans( n , vector<int>(m)) ; 
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            int newI = j ; 
            int newJ = n - i - 1 ; 
            ans[newI][newJ] = mat[i][j] ; 
        }
    } 

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m  ; j++) {
            mat[i][j] = ans[i][j] ; 
        }
    }
}  

vector<vector<int>> rotate(vector<vector<int>> &mat) {
    int n = mat.size() ; 
    int m = mat[0].size() ; 

    for(int i=0 ; i<n-1 ; i++) {
        for(int j=i+1 ; j<m ; j++) {
            swap( mat[i][j] , mat[j][i] ) ; 
        } 
    } 

    // reversing the columns of the matrix 
    reverse( mat[0].begin() , mat[0].end() )  ; 

    return mat ; 
}

int main() {
    int n ; 
    cin >> n ; 

    vector<vector<int>> mat( n , vector<int>(n)) ; 

    for(int i=0 ; i<n ; i++ ){
        for(int j=0 ;j<n ; j++) {
            cin >> mat[i][j] ; 
        }
    } 

    rotate(mat) ; 

    return 0 ; 
}