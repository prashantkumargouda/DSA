#include <iostream> 
#include <vector> 

using namespace std ;

int main() {
    int n ; 
    cin >> n ;

    vector<int> arr(n) ; 
    for(auto &it : arr) cin >> it ; 

    int maxi = arr[0] ; 
    for(int i=1 ; i<n ; i++) {
        maxi = max( arr[i] , maxi ) ; 
    } 

    cout << maxi << endl; 

    return 0 ; 
}