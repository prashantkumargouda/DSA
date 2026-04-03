#include <iostream>
#include <vector> 

using namespace std ; 

int gcd(int a, int b) { 
    if( b==0 ) return a ; 
    else{
        gcd(b, a%b) ; 
    }
} 

void leftRotate(vector<int> &arr, int d) { 
    int n = arr.size() ; 
    
    int cycles = gcd(n,d) ; 

    for(int i=0 ; i<cycles ; i++) { 
        int temp = arr[i] ; 
        int j=i ;  

        while( true ) {
            int k = ( j+d ) % n ; 
            if( k==i ) break ; 

            arr[j] = arr[k] ; 
            j = k ; 
        } 

        arr[j] = temp; 
    }

} 

int main() { 
    vector<int> arr = {1,2,3,4,5,6} ;  
    int d = 2 ; 
    leftRotate(arr ,d) ; 
    
    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << " " ; 
    } 

    cout << endl; 
    return 0 ;  
}