// finding the maximum consecutive ones present in an array 

#include <iostream> 
#include <vector> 
#include <climits> 

using namespace std ;  

int maxOnes(vector<int> &nums) {
    int n = nums.size() ; 

    int count = 0 ; 
    int maxi = INT_MIN ; 

    for(int i=0 ; i<n ; i++) { 
        if( nums[i] == 1 ) {
            count++ ;
        } 
        else if( nums[i] == 0 ) {
            maxi = max( count , maxi ) ;  
            count = 0 ;   
        }
    } 

    return maxi ; 
} 

int main(){
    int n;
    cin >> n; 

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ; 

    cout << maxOnes(nums) << endl; 

    return 0 ; 
    
}