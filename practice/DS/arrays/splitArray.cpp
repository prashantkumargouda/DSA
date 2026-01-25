// Split array into three equal sum segments 
// Input: arr[] = [1, 3, 4, 0, 4]
// Output: [1, 2]
// Explanation: 3 equal sum segments are: arr[0...1], arr[2...2] and arr[3...4] each having sum = 4.

#include <iostream> 
#include <vector> 

using namespace std ; 

int findSum(vector<int> &arr , int start , int end) {
    int n = arr.size() ; 
    int total = 0 ;
    for(int i=start ; i<= end ; i++){
        total += arr[i] ; 
    } 

    return total ; 
}

vector<int> findSplit(vector<int> &arr) {
    int n = arr.size() ; 

    for(int i=0 ; i<n-2 ; i++) {
        for(int j=i+1 ; j<n-1 ; j++) {
            int sum1 = findSum(arr,0,i) ;  
            int sum2 = findSum(arr, i+1 , j) ; 
            int sum3 = findSum(arr , j+1 , n-1) ;  

            if( sum1 == sum2 && sum2 == sum3 ) {
                return {i,j} ;
            }
        } 
    } 

    return {-1,-1} ; 
} 

vector<int> findSplit2(vector<int> &arr) {
    int n = arr.size() ; 
    vector<int> res ; 
    int total = 0 ; 

    for(int x : arr) {
        total += x ; 
    } 

    if(total % 3 != 0) return {-1,-1} ; 

    int currSum = 0 ; 

    for(int i=0 ; i<n ; i++) {
        currSum += arr[i] ; 

        if( currSum == total / 3 ) {
            currSum = 0 ;
            res.push_back(i) ;
        }  

        if( res.size() == 2 && i < n-1 ) {
            return res ;
        }
    } 

    return {-1,-1} ;
}

int main() {
    vector<int> arr = {1, 3, 4, 0, 4}; 
    vector<int> res = findSplit(arr) ; 

    for(int x:res) {
        cout << x << " " ;
    } 
    cout << endl; 
    
    vector<int> res1 = findSplit2(arr) ;
    for(int x : res1) {
        cout << x << " " ;
    } 

    cout << endl; 
    return 0 ; 
}