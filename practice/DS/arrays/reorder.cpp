#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std ; 

vector<int> reorder( vector<int> &arr , vector<int> &index) {
    int n = arr.size() ; 

    vector<vector<int>> paired ; 

    for(int i=0 ; i<n ; i++) {
        paired.push_back( {index[i] , arr[i]} ) ; 
    } 

    sort( paired.begin() , paired.end() ) ; 

    for(int i=0 ; i<n ; i++ ) {
        arr[i] = paired[i][1] ; 
    }
} 

vector<int> reorder2( vector<int> &arr , vector<int> &index) {
    int n = arr.size() ; 

    // using an auxillary array to store the values of the array according to the index array 

    vector<int> temp(n) ; 
    for(int i=0 ; i<n ; i++ ){
        temp[index[i]] = arr[i] ;  
    }  

    for(int i=0 ; i<n ; i++) {
        arr[i] = temp[i] ; 
    } 

    return arr ; 
    // return temp ;  

    // if I am going to put these in the same array 

} 
 
void reorder3(vector<int> &arr , vector<int> &index ) {
    int n = arr.size() ; 

    int i = 0 ; 

    while( i<arr.size() ) {
        if( i == index[i] ) {
            i++ ; 
        } 

        else {
            swap( arr[i] , arr[index[i]]) ;
            swap( index[i] , index[index[i]] ) ;  
        } 
    } 

} 

void reorder4(vector<int> &arr , vector<int> &index ) {
    int n = arr.size() ; 

    int maxVal = arr[0] ; 
    for(int i=1 ; i<n ; i++) {
        if( arr[i] > maxVal ) maxVal = arr[i] ; 
    } 

    int value = maxVal + 1 ; 

    // now using this to make the combined form for every index 
    // combined = old + new * value  
    // using this we can get the values required at those positions 
    // combined / value = new 
    // combined % value = old 

    for(int i=0 ; i<n ; i++){
        arr[index[i]] += ( arr[i] % value ) * value ;  
    }  

    for(int i=0 ; i<n ; i++) {
        arr[i] = arr[i] / value ; 
    } 

}
int main() { 
    vector<int> arr = {10,11,12} ; 
    vector<int> ind = {1,0,2} ; 

    reorder4(arr , ind) ; 
    for(int x : arr ) {
        cout << x << " " ;
    } 

    cout << endl; 

    return 0 ; 
}