// counting the maximun number of consecutive ones 

#include <iostream> 
#include <vector> 
#include <climits> 

using namespace std ; 

int findMax(vector<int> &arr){
    int n = arr.size() ; 

    // counting the ones 
    int count = 0 ; 
    int res = INT_MIN ; 
    for(int i=0 ; i<n ; i++) {
        if( arr[i] == 1 ) {
            count++ ;  
            res = max( res , count ) ; 
        }  
        else {
            count = 0 ; 
        }
    } 

    return res ; 
}
int main() {
    vector<int> arr = {1,1,1,3,4,1,1,5,7,8,9,1,1,1,1,1,0,2,10,11} ; 
    cout << findMax(arr) << endl; 

    return 0 ; 
}