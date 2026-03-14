#include <iostream>  
#include <vector> 
#include <climits> 

using namespace std ; 

int findingSecondLargest(vector<int> &arr) {
    int n = arr.size() ; 

    int largest = *max_element( arr.begin() , arr.end() ) ; 
    int second_largest = INT_MIN ; 

    for(int i=0 ; i<n ; i++) {
        if( arr[i] > second_largest && arr[i] != largest ){
            second_largest = arr[i] ; 
        }
    }

    return second_largest ; 
} 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> arr(n) ;
    for(auto &it : arr) cin >> it ; 

    int largest = INT_MIN ; 
    int second_largest = INT_MIN ; 

    for(int i=0 ; i<n ; i++) {
        if( arr[i] > largest ){
            second_largest = largest ; 
            largest = arr[i] ; 
        } 
        else if( arr[i] > second_largest && arr[i] != largest ) {
            second_largest = arr[i] ; 
        }
    } 

    cout << second_largest << endl; 
    return 0 ; 


}