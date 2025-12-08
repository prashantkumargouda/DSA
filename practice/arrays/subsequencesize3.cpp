#include <iostream> 
#include <vector> 

using namespace std ;

vector<int> findSequence(vector<int> &arr){
    int n = arr.size() ; 

    int min = 0 ; 
    int max = n-1 ; 

    vector<int> smaller( n , -1) ; 

    for(int i=1 ; i<n ; i++) {
        // start with the left most and compare 
        if( arr[i] >= arr[min] ) {
            smaller[i] = min ;  
        }else {
            min = i ; 
        }
    } 

    vector<int> greater(n , -1) ; 
    for(int i=n-2 ; i>=0 ; i--) {
        if( arr[i] <= arr[max] ) {
            greater[i] = max ;
        }else {
            max = i ; 
        }
    } 

    for(int i=0 ; i<n ; i++) {
        if( smaller[i] != -1 && greater[i] != -1) {
            return { arr[smaller[i]] , arr[i] , arr[greater[i]] } ;   
        } 
    }

    return {} ; 
} 



int main() { 
    vector<int> arr = {12, 11, 10, 5, 6, 2, 30}; 
    vector<int> res = findSequence(arr) ;  

    for(int x : res) {
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}