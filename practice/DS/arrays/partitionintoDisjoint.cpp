#include <iostream> 
#include <vector> 

using namespace std ; 

int check(vector<int> &nums) {
    int n = nums.size() ; 
    vector<int> prefixSum(n,0) ;  
    vector<int> suffixSum(n,0) ; 

    prefixSum[0] = nums[0] ; 

    for(int i=1 ; i<n ; i++) {
        prefixSum[i] = max ( nums[i] , prefixSum[i-1]) ;  
    } 

    suffixSum[n-1] = nums[n-1] ; 
    for(int i=n-2 ; i>= 0 ; i--) {
        suffixSum[i] = max( nums[i] , suffixSum[i+1] ) ; 
    } 

    int count = 0 ; 

    for(int i= 0 ; i<n ; i++) {
        if( prefixSum[i] <= suffixSum[i+1] ) {
            count = i+1 ; 
            break ; 
        }
    } 

    return count ; 

} 

int main() {

}