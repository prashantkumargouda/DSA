#include <bits/stdc++.h> 
using namespace std ; 

int secondSmallest(vector<int> &arr) {
    int n = arr.size() ; 

    int small = INT_MAX , second_small = INT_MAX; 
    for(int x : arr) {
        if( x < small ) {
            second_small = small ; 
            small = x ; 
        } 
        else if( x < second_small && x != small ) {
            second_small = x ; 
        } 
    } 

    return second_small ; 
} 

int secondLargest(vector<int> &arr) {
    int n = arr.size() ; 

    int maxi = INT_MIN , second_maxi = INT_MIN ; 
    for(int x : arr) {
        if( x > maxi ) {
            second_maxi = maxi ; 
            maxi = x ; 
        } 
        else if( x > second_maxi && x != second_maxi ) {
            second_maxi = x ; 
        }
    } 

    return second_maxi ; 
} 

int main() {
    vector<int> arr = {1,2,4,7,7,5} ; 

    cout << secondSmallest(arr) << endl; 

    return 0 ; 

}