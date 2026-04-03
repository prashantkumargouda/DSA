// printing all the subsequences with the sum k  

// using same recursion process of pick and not pick 

#include <iostream> 
#include <vector> 
using namespace std ;  

void subSqSum(int ind , vector<int> &ds , int arr[] , int n , int sum , int k ) {
    if( sum == k || ind >= n ) { 
        if( sum == k ) { 
            for(auto it : ds) { 
                cout << it << " " ; 
            } 
            cout << endl;  
        } 
        return  ; 
    } 

    sum = sum + arr[ind] ;  
    ds.push_back(arr[ind]) ;  
    subSqSum(ind + 1 , ds , arr , n , sum , k ); 

    sum = sum - arr[ind] ; 
    ds.pop_back();  
    subSqSum(ind +1 ,ds, arr, n , sum , k) ; 
}
int main() { 
    int arr[] = {3,5,2} ; 
    int k = 5 ;  

    int sum = 0 ;  
    int n = 3 ;  

    vector<int> ds;  
    subSqSum( 0 , ds , arr , n , sum , k ) ; 

    return 0 ; 
}