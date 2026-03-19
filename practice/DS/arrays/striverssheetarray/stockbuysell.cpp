#include <iostream> 
#include <vector>  
#include <climits> 

using namespace std ; 


int solve1(vector<int> &nums) {
    int n = nums.size() ; 

    int minPrice = INT_MAX ; 
    int maxProfit = 0 ; 

    for(int x : nums) {
        if( x < minPrice ) {
            minPrice = x ; 
        } 
        else {
            maxProfit = max( maxProfit , x - minPrice ) ;
        }
    } 

    return maxProfit; 
} 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> nums(n)  ; 
    for(auto &it : nums) cin >> it ;  

    cout << solve1(nums) << endl; 

    return 0 ; 

}