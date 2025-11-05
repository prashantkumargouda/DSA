// creating a function for the toboggan trajectory and using it to get the final solution 

#include <iostream>
#include <sstream>
#include <string> 
#include <vector> 

using namespace std ; 

int treeCount(vector<string> matrix , int right , int down ) {  
    int x = 0 , y = 0 , count = 0 ; 
    int height = matrix.size() ; 
    int width = matrix[0].size() ;  

    while( y < height ) { 
        if( matrix[y][x % width] == '#' ) {
            count++ ;
        } 

        x += right ; 
        y += down ; 
    } 

    return count ;  
}  

int main() { 
    string line ; 
    vector<string> matrix ; 

    while( getline(cin , line) && !line.empty() ) { 
        matrix.push_back(line) ; 
    }

    long long maxMul = 1 ;   

    vector<pair<int, int>> slopes = {
        {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}
    }; 

    // for(auto [r,d] : slopes ) {  
    //     maxMul *= treeCount(matrix , r , d ) ; 
    // } 

    for(auto slope : slopes ) {   
        int r = slope.first ; 
        int d = slope.second ; 
        maxMul *= treeCount(matrix , r , d ) ; 
    }

    // for(int i=0 ; i<5 ; i++){ 
    //     int r ;
    //     cout << "Enter r : " ; 
    //     cin >> r ; 
    //     cout << endl;  

    //     int l ; 
    //     cout << "Enter l :" ; 
    //     cin >> l  ;
    //     cout << endl;  

    //     maxMul = maxMul * treeCount(matrix , r , l ) ; 
    // } 

    cout << "multiplied value :" << maxMul << endl;  

    return 0 ; 
}