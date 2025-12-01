// Rearrange array such that even positioned are greater than odd 
// Given an array arr[], sort the array according to the following relations:  

// arr[i] >= arr[i - 1], if i is even, ∀ 1 <= i < n
// arr[i] <= arr[i - 1], if i is odd, ∀ 1 <= i < n 

#include <iostream> 
#include <vector>  
#include <algorithm> 
using namespace std ; 

vector<int> rearrangeArray(vector<int>& arr) {
        int n =arr.size() ; 
        
         for(int i=1 ; i<n ; i++) {
             if( i % 2 != 0 ) {  // even positioned 
                if( arr[i] < arr[i-1] ) {
                    swap(arr[i] , arr[i-1]) ; 
                } 
             } 
             else {
                 if( arr[i] > arr[i-1] ){
                     swap(arr[i] , arr[i-1]) ; 
                 } 
             }
         } 
         
         return arr ; 
        
    }
// // using another vector here to store the values and return the vector 
// vector<int> rearrangeArray(vector<int> &arr) { 
//     int n = arr.size() ; 

//     int ptr1 = 0 ; 
//     int ptr2 = n-1 ; 

//     vector<int> ans(n) ; 
//     sort(arr.begin() , arr.end()) ; 

//     for(int i=0 ; i<n ; i++) {
//         // here I need to check if odd or not and keep adding those values 

//         if( i % 2 != 0 ) {
//             ans[i] = arr[ptr2--] ; 
//         } 
//         else{
//             ans[i] = arr[ptr1++] ; 
//         }
//     } 

//     return ans ; 
// } 


int main() {
    vector<int> arr = {1, 2, 2, 1};

    vector<int> res = rearrangeArray(arr);
    for (auto it : res)
        cout << it << " ";
    return 0;
}