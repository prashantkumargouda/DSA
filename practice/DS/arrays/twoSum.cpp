#include <iostream>
#include <vector> 
#include <algorithm> 
#include <unordered_set> 

using namespace std ; 

int two(vector<int> &arr , int target ) {
    int n = arr.size() ; 

    for(int i=0 ; i<n ; i++ ){
        for(int j=i+1 ; j<n ; j++) {
            if(arr[i] + arr[j] == target ) return true ; 
        }
    } 
    return false ; 
} 

bool binarySearch(vector<int> &arr ,int start , int end , int target ) {
    while(start <= end) { 
        int mid = start + (end - start) / 2 ; 
        if( target > arr[mid] ) {
            start = mid + 1 ; 
        } 
        else if( target < arr[mid] ) {
            end = mid -1 ; 
        }else{
            return true ;
        }
    } 
    return false ; 
} 

bool twoSum2(vector<int> &arr , int target ) {
    int n = arr.size() ; 

    // using the binary search method  
    // it makes use of a complement along with binary search to find if it exists 
    sort(arr.begin() , arr.end()) ; 

    for(int i=0 ; i<n ; i++) {
        int comp = target - arr[i] ; 

        if( binarySearch(arr , i+1 , arr.size() - 1 , comp )) {
            return true ; 
        }
    } 

    return false ; 
} 

int twoSum3(vector<int> &arr , int target ) {
    int n = arr.size() ;

    // making use of two pointers technique to find the solution \ 
    sort(arr.begin() , arr.end() ) ; 

    int left = 0 ; 
    int right = n-1 ; 

    while(left < right) {
        int sum = arr[left] + arr[right] ; 

        if( sum > target ){
            right-- ;
        } 
        else if( sum < target) {
            left++ ;
        } 
        else {
            return true ;
        }
    } 
    return false ;  
} 

int twoSum4(vector<int> &arr , int target){
    int n = arr.size() ; 

    // using an unordered_set to store the solution and check if its complement exists 
    unordered_set<int> st ;  
    for(int i=0 ; i<n ; i++){
        int comp = target - arr[i] ; 

        if(st.find(comp) != st.end() ) {
            return true ;
        } 
        
        st.insert(arr[i]) ;
    } 

    return false ; 
}
int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if(two(arr, target))
      cout << "true";
    else
      cout << "false";

      
    if(twoSum2(arr, target))
      cout << "true";
    else
      cout << "false";

      
    if(twoSum3(arr, target))
      cout << "true";
    else
      cout << "false";
   
    if(twoSum4(arr, target))
      cout << "true";
    else
      cout << "false";

    return 0;
}