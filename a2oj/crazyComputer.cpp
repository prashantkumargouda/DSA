#include <iostream>
#include <vector> 

using namespace std ; 

int main(){
    int n ,c ; 
    cout << "Enter the values of n and c " << endl; 
    cin >> n >> c ; 

    vector<int> arr(n) ;  


    for(int i=0 ; i<n ; i++) {
        cin >> arr[i] ; 
    }  

    int wordCount = 0 ; 

    for(int i=0 ; i<n-1 ; i++){
        if( arr[i+1] - arr[i] > c ){
            wordCount = 0 ; 
        } else { 
            wordCount += 1 ; 
        }
    } 

    cout << wordCount + 1 << endl; 
    return 0 ; 
}  

