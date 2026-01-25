// // move the zeros in an array to the end 
// #include <iostream>   
// #include <vector> 
// using namespace std ; 

// void moveZeros(vector<int> &arr){
//     int n = arr.size() ;  
//     // okay now what should I do 
//     int count = 0 ; 
    
//     for(int i=0 ; i<n ; i++) { 
//         if( arr[i] != 0 ){
//             arr[count++] = arr[i] ; 
//         }
//     } 

//     while( count < n ){
//         arr[count++] = 0 ; 
//     } 
// } 

// int main() { 
//     vector<int> arr = {1,2,0,0,3,4,0,0,5} ; 

//     moveZeros(arr) ; 

//     for(int i=0 ;i<arr.size() ; i++) {
//         cout << arr[i] << " "; 
//     } 
//     cout << endl; 
//     return 0 ;
// }

#include <iostream>
#include <vector> 
using namespace std ; 

void moveZeros(vector<int> &arr) {
    int n = arr.size() ; 

    int count = 0 ; 

    for(int i=0 ; i<n ; i++) {
        if( arr[i] != 0 ) {
            swap(arr[count] , arr[i]) ;
            count++ ; 
        }
    }
} 

int main() { 
    vector<int> arr = {1,2,0,0,3,4,0,0,5} ;  
    moveZeros(arr) ; 
    for(int i : arr) {
        cout << i << " " ; 
    } 

    cout << endl; 
    return 0 ; 
}