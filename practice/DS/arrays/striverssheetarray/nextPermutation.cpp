// find the next permutation for the given element 

#include <iostream>   
#include <vector> 
#include <algorithm> 

using namespace std ; 

vector<int> solve1(vector<int> &nums) {
    int n = nums.size() ; 

    int ind = -1 ; 
    for(int i=n-1 ; i>=0 ; i--) {
        if( nums[i] < nums[i+1] ) {
            ind = i ; 
            break ; 
        }
    } 

    if( ind == -1 ) {
        reverse(nums.begin() , nums.end()) ;  
        return nums ;
    }  

    for(int i=n-1 ; i>ind ; i--) {
        if( nums[i] > nums[ind] ) {
            swap(nums[i] ,nums[ind]) ;  
            break ; 
        }
    } 

    reverse(nums.begin() + ind + 1 , nums.end() ) ; 
    
    return nums ; 
} 

int main() { 
    int n ; 
    cin >> n ;  

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ;  

    vector<int> temp = solve1(nums) ; 

    for(auto it: temp){ 
        cout << it << " " ; 
    } 

    cout << endl; 

    return 0 ; 
} 

