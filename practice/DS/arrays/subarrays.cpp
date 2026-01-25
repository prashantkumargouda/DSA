#include <iostream>
#include <vector> 
using namespace std ; 

// naive approach 
int subArrays(vector<int> &arr){
    int n = arr.size() ; 

    int sum = 0 ;  
    for(int i=0 ; i<n ; i++) { 
        int temp = 0 ; 
        for(int j=i; j<n ; j++) {
            temp += arr[j] ;  
            sum += temp ; 
        } 
    } 
    return sum ;
} 

// expected approach 

int subArrays2(vector<int> &arr) { 
    int n = arr.size() ; 
    int result = 0 ;  

    for(int i=0 ; i<n ; i++) {
        result += (arr[i]) * ( i+1 ) * (n-i) ; 
    } 

    return result ; 
} 



int main() {
    vector<int> arr = {1,4,5,3,2}; 

    int ans = subArrays2(arr) ; 
    cout << ans << endl; 

    return 0 ; 

}