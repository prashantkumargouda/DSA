#include <iostream> 
#include <vector> 
#include <climits>

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

vector<int> find3Sequence(vector<int> &arr) {
    int n = arr.size() ; 
    
    if( n < 3) return {} ; 

    int first = arr[0] ; 
    int second = INT_MAX ; 

    int first_for_second = first ; // initially the first element for second is first only  

    for(int i=1 ; i<n ; i++) {
        if( arr[i] == first ) continue ; 

        else if( arr[i] < first ) {
            first = arr[i] ; 
            continue ; 
        }  
        else if( arr[i] > first && arr[i] < second ) {
            second = arr[i] ; 
            first_for_second = first ; 
        } 

        else if( arr[i] > second ) { 
            return {first_for_second , second , arr[i] } ;
        }
    } 

    return {} ; 
}


int main() { 
    vector<int> arr =   {1, 2, -1, 7, 5} ; 
    vector<int> res = find3Sequence(arr) ;  

    for(int x : res) {
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}