//  return the index of subarray equal to sum  

#include <iostream> 
#include <vector> 

using namespace std ; 

vector<int> sumSub(vector<int> &arr ,int x) { 
    // Naive Approach 
    int n = arr.size() ; 

    vector<int> res ; 

    for(int i=0 ; i<n ;i++) {
        int sum = 0 ; 

        for(int j=i ; j<n ; j++) {
            sum += arr[j] ; 

            if( sum == x ) {
                res.push_back(i+1) ; // 1 indexed hai isliye + 1  
                res.push_back(j+1) ; 
                return res ; 
            }
        }
    } 

    return {-1} ; 
} 

vector<int> sumSub2(vector<int> &arr , int target ){
    int i=0 , j=0 , sum = 0 ; 

    while( j < arr.size() ) {
        sum += arr[j] ; 

        while( sum > target && i<=j ) {
            sum -= arr[i++];
        } 

        if( sum == target ) {
            return {i+1 , j+1} ; 
        }    

        j++ ; 
    } 

    return {-1} ; 
}

int main() {
    vector<int> arr =  {15, 2, 4, 8, 9, 5, 10, 23};  
    vector<int> temp = sumSub(arr, 23) ; 
    
    for(int x:temp) {
        cout << x << " " ; 
    } 

    cout << endl;  

    vector<int> temp1 = sumSub2(arr , 23) ; 

    for(int x : temp1) {
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}