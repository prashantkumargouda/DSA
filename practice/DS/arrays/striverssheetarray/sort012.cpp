// sort an array of 0's 1's 2's using dutch national flag algorithm 

#include <iostream> 
#include <vector> 

using namespace std ;
 
vector<int> solve1(vector<int> &nums) {
    int n = nums.size() ;  

    int count0 = 0 ; 
    int count1 = 0 ; 
    int count2 = 0 ; 

    for(int i=0 ; i<n ; i++) {
        if( nums[i] == 0 ) count0++ ; 
        else if( nums[i] == 1 ) count1++ ; 
        else count2++ ; 
    } 
    
    int index = 0 ; 

    while(count0--){
        nums[index++] = 0 ; 
    } 

    while(count1--) {
        nums[index++] = 1 ; 
    } 

    while(count2--) {
        nums[index++] = 2 ; 
    } 

    return nums ; 
}  

vector<int> solve2(vector<int> nums) {
    int n = nums.size() ; 

    int low = 0 , mid = 0 , high = n-1 ; 

    while( mid <= high ) {
        if( nums[mid] == 0 ){
            swap( nums[mid] , nums[low] ) ;  
            low++ ; 
            mid++ ; 
        } 
        else if( nums[mid] == 1 ) {
            mid++ ; 
        } 
        else{
            swap(nums[mid] , nums[high]) ; 
            high-- ; 
        }
    }  
    
    return nums ; 
}

int main() {
    int n; 
    cin >> n ; 

    vector<int> nums(n) ;
    for(auto &it : nums) cin >> it ; 

    vector<int> temp = solve2(nums) ; 

    for(auto &it : temp) { 
        cout << it << " " ; 
    } 

    cout << endl;

    return 0 ; 
}