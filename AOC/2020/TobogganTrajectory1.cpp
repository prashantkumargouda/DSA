#include <iostream>
#include <vector>
#include <string> 

using namespace std ; 

int main() { 
    // string line ; 
    // vector<vector<char>> matrix ;  

    // while(true) { 
    //     getline(cin , line) ; 
    //     if(line.empty()) break ; 

    //     vector<char> row ; 
    //     for(char c : line) {
    //         row.push_back(c) ; 
    //     } 

    //     matrix.push_back(row) ; 
    // } 

    // for(auto &row : matrix) { 
    //     for(auto &val : row ) { 
    //         cout << val ;  
    //     } 
    //     cout << endl; 
    // } 

    // string row ; 
    // vector<string> matrix ; 

    // in the second approach no need to extract that line and then put into row and push into matrix no need of doing that shit 
    
    // while( getline(cin , row) && !row.empty() ) { 
    //     matrix.push_back(row) ; 
    // } 

    // for(auto &row : matrix) { 
    //     cout << row << endl; 
    // } 

    // return 0 ;  

    // now solving the problem  

    string line ; 
    vector<string> matrix ; 

    while( getline(cin , line) && !line.empty() ) { 
        matrix.push_back(line) ; 
    } 
 
    // ok now how to traverse this thing in right 3 down 2  ? and count the number of trees  

    int height = matrix.size() ; 
    int width = matrix[0].size() ;   

    int right = 3 ; 
    int down = 1 ; 

    int x = 0 , y = 0 ;
    int count = 0 ;  

    while( y < height ) { 
        if( matrix[y][x % width] == '#' ) { 
            count++ ;
        }  
        
        x += 3 ; 
        y += 1 ;  
    }

    cout << count << endl;  

    return 0 ; 
    // okay got the rows and col size now what ? 
    // we need to move right 3 and down 2 how ? 
    // using y = (y+3) % cols ; 
    // and using x = x + 3 ;  

    // here x --> j(right) and y --> i(down)  

}