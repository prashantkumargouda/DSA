#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 

void bfs(int row , int col , vector<vector<int>> &image , int color , int check) {
    image[row][col] = color ; 

    queue<pair<int , int>> q ; 
    q.push({row , col}) ; 

    int rows = image.size() ; 
    int cols = image[0].size() ; 

    vector<int> delRow = {-1 , 0 , 1 , 0} ; 
    vector<int> delCol = {0 , 1 , 0 , -1} ; 

    while( !q.empty() ) {
        int r = q.front().first ; 
        int c = q.front().second ; 
        
        q.pop() ; 

        for(int i=0 ; i<4 ; i++) {
            int nrow = r + delRow[i] ; 
            int ncol = c + delCol[i] ; 

            if( nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && image[nrow][ncol] == check ) {
                image[nrow][ncol] = color ; 
                q.push({nrow , ncol}) ;  
            }
        }
    }
} 

vector<vector<int>> floodFill(vector<vector<int>> &image , int sr , int sc , int color) {
    // I should change all the connected components into color 
    // find separate components 

    int row = image.size() ; 
    int col = image[0].size() ; 

    int check = image[sr][sc] ;

    if( check == color ) return image ; 
    
    bfs(sr , sc , image , color , check) ; 

    return image ; 
} 

int main(){
    vector<vector<int>> temp = {{1,1,1} , {1,1,0} , {1,0,1}} ; 

    vector<vector<int>> res = floodFill(temp , 1 , 1 , 2) ;  

    for(auto it: res){
        for(int i : it) {
            cout << i << " "; 
        } 
        cout << endl; 
    } 

    return 0 ; 
}