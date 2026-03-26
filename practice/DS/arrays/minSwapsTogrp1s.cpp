// finding the minimum no of swaps required to grp all 1's together 

#include <iostream>  
#include <vector> 

using namespace std ; 

int minSwaps(vector<int> &nums) {
    int n = nums.size() ; 
    int left = 0 ; 
    int right = n-1 ; 

    int count = 0 ; 
    while(left <= right) {
        if( nums[left] == 0 ) {
            if( nums[right] == 1 ) {
                swap(nums[left] , nums[right] ) ;  
                count++ ; 
                left++ ; 
                right-- ; 
            }else {
                right-- ; 
            } 
        } 
        else {
            left++ ; 
        }
    }

    return count ; 

} 

int main() {
    int n ; 
    cin >> n ; 
    
    vector<int> nums(n) ;
    for(auto &it : nums) cin >> it ; 

    cout << minSwaps(nums) << endl;  

    return 0 ; 
}