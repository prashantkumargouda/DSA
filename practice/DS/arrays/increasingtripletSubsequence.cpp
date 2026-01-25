#include <iostream>  
#include <vector>  
#include <climits> 

using namespace std ; 

bool triplets(vector<int> &nums) {
    int first = INT_MAX ; 
    int second = INT_MAX ; 
     
    for(int num : nums) {
        if( num <= first ) {
            first = num ; 
        }else if( num <= second ) {
            second = num ; 
        }else {
            return true ; 
        }
    } 

    return false ; 
}
int main() {
    vector<int> arr = {1,2,3,4,5} ;  

    cout << triplets(arr) << endl; 

    return 0 ; 
}