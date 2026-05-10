#include <iostream> 
#include <vector> 

using namespace std ; 

int main() {
    int t ; 
    cin >> t ; 

    while( t-- ) {
        int n ; 
        cin >> n ; 

        vector<int> arr(n) ; 

        for(int i=0 ; i<n ;i++){
            cin >> arr[i] ; 
        } 

        bool flag = false  ;  

        // traversing and finding the product with each number 
        // 1 7 6 7 67 
        // create subarrays for this and try to find the product 
        for(int i=0 ; i<n ; i++) {
            if( arr[i] == 67 ) {
                flag = true ; 
                break ; 
            }  
        }  

        if( flag ) {
            cout << "YES" << endl; 
        } 

        else {
            cout << "NO" << endl; 
        }
    } 

    return 0 ; 
} 