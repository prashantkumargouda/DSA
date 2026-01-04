//Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
// horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Input 1 
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true  

// Input 2 
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

#include <iostream> 
#include <vector>
#include <string> 
#include <set> 

using namespace std ; 

// okay so for this dfs time limit exceeds 
// what I can avoid using is the set vector  
// but that will just reduce the size ig  

bool dfs(vector<vector<char>> &board ,string word , int i , int j , int k , set<vector<int>> &st) { 
    int rows = board.size() ; 
    int cols = board[0].size() ;  

    if( k == word.size() ) return true ; 

    // these conditions where our search fails
    if( i<0 || i>=rows || j<0 || j>=cols || st.find({i,j}) != st.end() || board[i][j] != word[k] ) return false ; 

    if( board[i][j] == word[k] ){
        st.insert({i,j}) ; 

        bool res =  dfs(board , word, i+1 , j, k+1 , st ) || 
                    dfs(board , word , i-1 , j , k+1 , st) || 
                    dfs(board , word , i , j+1 , k+1 , st) || 
                    dfs(board , word , i , j-1 , k+1 ,st ) ;  
        
        st.erase({i,j}) ; 
        return res ; 
    }  

    return false ; 
}

bool dfs1(vector<vector<char>> &board ,string word , int i , int j , int k) { 
    int rows = board.size() ; 
    int cols = board[0].size() ;  

    if( k == word.size() ) return true ; 

    // these conditions where our search fails
    if( i<0 || i>=rows || j<0 || j>=cols ||  board[i][j] != word[k] ) return false ; 

    
    board[i][j] = '#' ; 

    bool res =  dfs1(board , word, i+1 , j, k+1  ) || 
                dfs1(board , word , i-1 , j , k+1) || 
                dfs1(board , word , i , j+1 , k+1 ) || 
                dfs1(board , word , i , j-1 , k+1 ) ;  
        
    board[i][j] = word[k] ; 

    return res ; 
}

bool exist(vector<vector<char>> board , string word ) {
    int rows = board.size() ; 
    int cols = board[0].size() ;    

    set<vector<int>> st ; 

    if( word.size() > rows * cols ) return false ; 
    
    // so the first thing I am going to check is if the first element of the word 
    // is matching with the element I am currently at 
    
    // for(int i=0 ; i<rows ; i++) {
    //     for(int j=0 ; j<cols ; j++) {
    //         if( word[0] == board[i][j] ) {
    //             if(dfs1(board , word , i , j , 0 , st) ) return true ; 
    //         }
    //     }
    // } 
    for(int i=0 ; i<rows ; i++) {
        for(int j=0 ; j<cols ; j++) {
            if( word[0] == board[i][j] ) {
                if(dfs1(board , word , i , j , 0 ) ) return true ; 
            }
        }
    } 
    return false ; 
} 

int main() { 
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}} ; 
    string word = "ABCCED" ; 

    if( exist(board , word) ) {
        cout << "TRUE" << endl;  
    } 
    else {
        cout << "FALSE" << endl;
    } 

    return 0 ; 
    
}