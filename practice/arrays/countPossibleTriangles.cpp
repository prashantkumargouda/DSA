#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std ; 

int countTri1(vector<int> &arr) {
    int n = arr.size() ; 
    int count = 0 ; 
    // checking all the triplets  
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++) {
                if( arr[i] + arr[j] > arr[k] && arr[k] + arr[i] > arr[j] && arr[j] + arr[k] > arr[i] ) {
                    count++ ; 
                } 
            }
        }
    } 

    return count ;  

} 

int countTri2(vector<int> &arr) {
    int n = arr.size() ; 

    // using binary search 

    sort( arr.begin() , arr.end() ) ;  

    // here I am going to use lower_bound to perform the binary search 
    // lower_bound lives in algorithm and takes three arguments  
    // first is starting index , ending index , element to search 
    // it returns the first element which >= to the ELEMENT 

    int res = 0 ;  

    // intution yeh hai ki  
    // do sides fix karo 
    // phir values nikalo jahan pe it is greater than the sum = arr[i] + arr[j] 
    // uske pehle ki saari values form a valid trinagle  
    // using lowerbound  

    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            int k = lower_bound( arr.begin() + j + 1 , arr.end() , arr[i] + arr[j] ) - arr.begin() ;  
            // subtrated the arr.begin()  to make the lowerBound value integer 
            // lower_bound returns a pointer to that index   

            int count = k - (j+1) ; 
            res += count ; 
        } 
    }   

    return res ; 
}

int countTri3(vector<int> &arr) {
    int n = arr.size() ; 

    // using two pointers approach 
    int res = 0 ; 

    for(int i=2 ; i<n ; i++) {
        int left = 0 , right = i-1 ; 

        while( left < right ) {
            if( arr[left] + arr[right] > arr[i] ) {
                // if right is working 
                // then any value greater than left till right 
                // is going to work fine 
                // thats why used right - left 
                // arr[left] + arr[right] > arr[i] 
                // arr[left+1] + arr[right] > arr[i] 
                // arr[left + 2 ] + arr[right] > arr[i] 
                res += right - left ;  
                // for more smaller values to check 
                right-- ; 
            } else{  
                // for larger values to check 
                left++ ; 
            }
        }
    } 

    return res ; 
} 

int main() {
    vector<int> arr = {4,6,3,7} ; 
    cout << countTri1(arr) << endl; 
    cout << countTri2(arr) << endl;  
    cout << countTri3(arr) << endl; 
    return 0 ; 
}