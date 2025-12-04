#include <iostream> 
#include <vector> 
using namespace std ; 

int maxSum(vector<int> &price , int start , int end) {
    // start and end  
    int res = 0 ; 
    for(int i=start ; i<end ; i++) {
        for(int j=i+1 ; j<end ; j++) {
            if( price[j] > price[i] ) {
                int curr = price[j] - price[i] + maxSum(price , start , i-1 ) + maxSum(price , j+1 , end) ;  

                res = max(curr , res) ; 
            }  
        }
    } 
    return res ; 
} 

int maxSum2(vector<int> &price) {
    int n = price.size() ;   

    int res = 0 , lmax = price[0] , lmin = price[0] ;  

    int i=0 ; 
    while( i < n-1 ) {
        // continuosly move to the right to get the local minima first 
        while( i < n-1 && price[i] >= price[i+1] ){i++;}  
        lmin = price[i] ;  

        // keep moving until u find the local maxima 
        while( i<n-1 && price[i] <= price[i+1] ) {i++;} 
        lmax = price[i] ; 
        
        res = res + (lmax - lmin) ; 
    } 

    return res;  
}

int maxSum3(vector<int>&price) { 
    int n = price.size() ; 

    int res = 0 ; 
    // keep couting the profits as u keep moving if the previous value is smaller than the present value 
    for(int i=1 ; i<n ; i++) {
        if( price[i] > price[i-1] ) {
            res += price[i] - price[i-1] ;    
        }
    }  

    // else skip it 

    return res ; 
} 

int main() {
    vector<int> arr = {100,180,260,310,40,535,695} ; 

    int profit = maxSum(arr , 0 , arr.size() ) ;  

    cout << profit << endl; 

    cout << maxSum2(arr) ;  
    cout << endl; 
    cout << maxSum3(arr) ; 
    return 0 ; 
}


