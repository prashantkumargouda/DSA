#include <iostream>
#include <vector> 
using namespace std ; 

void merge(vector<int> &arr , int low , int mid , int high ) { 
    int left = low ; 
    int right = mid + 1 ;  

    vector<int> temp ; 

    while( left <= mid && right <= high ) { 
        if(arr[left] <= arr[right]) { 
            temp.push_back(arr[left]) ; 
            left++ ; 
        } 
        else { 
            temp.push_back(arr[right]) ; 
            right++ ; 
        }
    } 

    while( left <= mid ) { 
        temp.push_back(arr[left++]) ; 
    } 
    while( right <= high ) { 
        temp.push_back(arr[right++]) ; 
    } 

    for(int i=low ; i<= high ; i++) { 
        arr[i] = temp[i-low] ; 
    }  
} 

void mergeSort(vector<int> &arr , int low , int high ) { 
    if( low == high ) return ; 

    int mid = (low + high) / 2 ;  
    mergeSort(arr , low , mid) ; 
    mergeSort(arr , mid + 1 , high ) ;  

    merge(arr , low , mid , high ) ; 
} 

int main() { 
    vector<int> arr = {3,1,2,4,1,2,4,5,6} ;
    mergeSort(arr , 0 , arr.size() - 1  ) ;

    for(auto &cp : arr) {
        cout << cp << " " ; 
    } 
    cout << endl; 
    
    return 0 ; 
} 

