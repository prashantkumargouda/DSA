#include <iostream>
#include <algorithm>
#include <vector> 
#include <unordered_map>  

using namespace std ; 

int findMajority0(vector<int> &arr) {
    int n = arr.size(); 

    for(int i=0 ; i<n ; i++){
        int count = 0 ; 
        for(int j=0 ; j<n ; j++) {
            if( arr[i] == arr[j] ) {
                count++ ; 
            }
        } 

        if( count > n/2 ) {
            return arr[i] ;
        }
    } 

    return -1 ; 
} 

int findMajority1(vector<int> &arr) {
    int n = arr.size() ; 

    sort( arr.begin() , arr.end() ) ; 

    int i=0 ;  
    while( i < arr.size() - n/2 ) {
        if( arr[i] == arr[i + n/2 ] ) {
            return arr[i] ;
        } 
        i++ ;
    } 

    return -1 ; 
}  

int findMajority2(vector<int> &arr) {
    int n = arr.size() ; 

    // okay so sorting out the elements and 
    // uske baad use the 
    // potentital majority element  

    int count = 0 ; 

    sort( arr.begin() , arr.end() ) ; 
    int candidate = arr[n/2] ; 
    for(int num: arr) { 
        if( num == candidate )  {
            count++ ;
        }
    }  

    if( count > n/2 ) {
        return candidate ; 
    } 

    return -1 ; 
} 

int findMajority3(vector<int> &arr) {
    int n = arr.size() ; 

    // using a hashmap 

    unordered_map<int , int> countMap ;  

    for(int x : arr) {
        countMap[x]++ ; 

        if( countMap[x] > n/2 ) {
            return x ; 
        }
    } 

    return -1 ; 
} 

int mooresMajority(vector<int> &arr){
    int n = arr.size() ; 

    // this happens initially 
    int count = 0 , candidate = -1 ; 

    for(int num : arr) {
        if( count == 0 ) {
            candidate = num ; 
            count = 1 ; 
        } 
        else if( num == candidate ) {
            count++ ;
        } 
        else{
            count-- ; 
        } 
        // here found the potential candidate  
    } 

    count = 0 ; 
    for(int num : arr) {
        if( num == candidate ) {
            count++ ; 
        } 
    } 

    if( count > n/2 ) {
        return candidate ; 
    } 
    else {
        return -1 ; 
    }

}

int main() {
    vector<int> arr = {1, 5, 2, 5, 3, 5, 5};   

    cout << findMajority0(arr) << endl; 
    cout << findMajority1(arr) << endl; 
    cout << findMajority2(arr) << endl;  
    cout << findMajority3(arr) << endl; 
    cout << mooresMajority(arr) << endl;  

    return 0 ; 
}