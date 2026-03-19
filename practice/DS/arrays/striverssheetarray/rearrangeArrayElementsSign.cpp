// Problem Statement: There's an array 'A' of size 'N' with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include <iostream>  
#include <vector> 

using namespace std ;

vector<int> solve1(vector<int> &nums) {
    int n ;
    cin >> n ; 

    vector<int> ans( n , 0 )  ; 

    int pos = 0 ; 
    int neg = 1 ; 

    for(int i=0 ; i<n ; i++) {
        if( nums[i] > 0 ) {
            ans[pos] = nums[i] ; 
            pos += 2 ; 
        } 
        else{
            ans[neg] = nums[i] ; 
            neg += 2 ;
        }
    } 

    return ans ; 
}  


int main() {
    int n ; 
    cin >> n ; 

    vector<int> nums(n)  ; 
    for(auto &it : nums) cin >> it ; 


}
