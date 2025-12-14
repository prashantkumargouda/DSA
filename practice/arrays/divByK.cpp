// Given an array of integers of size n and an integer k, find all the pairs in the array whose absolute difference is divisible by k. 
// n = 3
// arr[] = {3, 7, 11}
// k = 4 

#include <iostream> 
#include <vector> 
#include <unordered_map> 

using namespace std ; 

int countDivByK(vector<int> &arr , int k ) { 
    // Naive approach

    int n = arr.size() ; 
    int count = 0 ; 
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(abs(arr[i] - arr[j]) % k == 0) {
                count++ ; 
            }
        }
    }

    return count ; 
} 

int countDivByK2(vector<int> &arr , int k ) {
    int n = arr.size() ; 
    int count = 0 ; 
    // using an unordered_map 
    unordered_map<int , int> mp ; 

    for(int x : arr) { 
        int rem = ((x%k) + k ) %k ;
        mp[rem]++ ;
    } 

    for(auto &it : mp){
        int c = it.second ; 
        count += c * (c -1) / 2 ; 
    } 

    return count ; 
} 

int countDivByK3(vector<int> &arr , int k ) {
    int n = arr.size() ; 

    unordered_map<int , vector<int>> mp ; 

    for(int x : arr) {
        int rem = ((x%k) + k ) %k ; 
        mp[rem].push_back(x) ; 
    } 

    for(auto &it : mp){
        vector<int> v = it.second ; 
        int m = v.size() ; 

        for(int i=0 ; i<m ; i++ ){
            for(int j=i+1 ; j<m ; j++) {
                cout << "(" << v[i] << "," << v[j] << ")" << endl; 
            }
        } 

    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4} ; 
    cout << countDivByK(arr , 2) << endl; 
    cout << countDivByK2(arr , 2) << endl; 

    countDivByK3(arr , 2) ; 

    return 0 ; 

}