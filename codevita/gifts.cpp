// finding the total number of gifts required to be distributed among the employess based on the ranks  


// if neighbour's rank is higher simply give more gift(+1) to the greater ranked neighbour 

#include <iostream>
#include <vector> 
using namespace std ;  

void fGift(vector<int> &arr , int n , vector<int> &gifts , int &sum ) { 
    gifts.assign( n , 1 ) ;  

    // going to check for both neighbouring values in 2 diff loops 
    for(int i=1 ; i<n ; i++) { 
        if( arr[i] > arr[i-1] ) {  // checking for all the previous values in left to right loop 
            gifts[i] = gifts[i-1] + 1 ;  
        }
    } 

    for(int i=n-2 ; i>= 0 ; i-- ) {  // now checking for all the next values in right to left loop 
        if( arr[i] > arr[i+1] ) { 
            gifts[i] = max( gifts[i+1] + 1 , gifts[i] ) ; 
        }
    } 

    for( auto it : gifts ){ 
        cout << it << " ";  
        sum += it ; 
    } 

    cout << endl ; 
    cout << sum << endl; 
} 
 
int main() { 
    int n ; 
    cout << "Enter the number of employees : " << endl;  

    cin >> n ;  

    vector<int> arr(n);   

    cout <<"Enter the array values :" << endl;  

    for(int i=0 ; i<n ; i++) { 
        cin >> arr[i] ; 
    } 

    int sum = 0; 
    vector<int> gifts ;   
    fGift(arr , n , gifts , sum) ; 

    return 0 ; 


}