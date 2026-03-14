// removing duplicates from a sorted array 

#include <iostream>  
#include <vector> 

using namespace std ;

int removeDuplicates(vector<int> &nums) {
    int n = nums.size() ;   

    if( nums.empty() ) {
        return 0 ; 
    } 

    int k = 0 ; 
    for(int i=1 ; i<n ; i++){
        if( nums[i] != nums[i-1] ){
            k++ ; 
            nums[k] = nums[i] ; 
        }
    } 

    return k + 1 ; 

} 

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4} ; 
    cout << removeDuplicates(nums) << endl; 
    
    for(int i : nums) {
        cout << i << " " ; 
    } 
    cout << endl; 
    return 0 ; 
}