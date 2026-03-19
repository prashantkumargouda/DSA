// finding the majority element in the array 

#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include <algorithm> 

using namespace std ;

int solve1(vector<int> &nums) {
    int n = nums.size() ;

    for(int i=0 ; i<n ; i++) {
        int count = 0 ; 

        for(int j=0 ; j<n ; j++) {
            if( nums[j] == nums[i] ) {
                count++ ;
            }
        } 

        if( count > (n/2) ) {
            return nums[i] ; 
        }
    } 

    return -1 ; 
} 

int solve2(vector<int> &nums) {
    int n = nums.size() ; 
    
    unordered_map<int , int> mp ; 

    for(int num : nums) {
        mp[num]++ ;
    } 

    for(auto &it : mp) {
        if( it.second > (n/2) ) {
            return it.first ; 
        }
    }

    return -1 ; 
} 

int solve3(vector<int> &nums) {
    int n = nums.size() ; 
    sort( nums.begin() , nums.end() ) ;  

    int check = nums[n/2] ; 

    int count = 0 ; 
    for(int num : nums) {
        if( num == check ) {
            count++ ; 
        } 
    }  

    if( count > n/2 ){
        return check ; 
    } 

    return -1 ; 
}

int solve4(vector<int> &nums) {
    int n = nums.size() ; 

    int el ; 
    int count = 0 ; 

    for(int i=0 ; i<n ; i++){
        if( count == 0 ) {
            count++ ; 
            el = nums[i] ; 
        } 

        else if( nums[i] == el ) {
            count++ ; 
        } 
        
        else {
            count-- ; 
        }
    } 

    int cnt = 0 ; 

    for(int i=0 ; i<n ; i++) {
        if( el == nums[i] ) {
            cnt++ ;
        } 
    }  

    if( cnt > (n/2) ) {
        return el ; 
    } 

    return -1 ; 
} 

int solve5(vector<int> &nums) {
    int n = nums.size() ;

    int candidate; 
    int count = 0 ; 

    for(int num : nums) {
        if( count == 0 ) candidate = num ; 
        count += ( num == candidate ) ? 1 : -1 ; 
    }  

    int cnt = 0 ; 
    for(int num : nums) {
        if( num == candidate ) cnt++ ; 
    } 

    if( cnt > (n/2) ) {
        return candidate ; 
    }

    return -1 ; 
} 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ; 


    cout << solve3(nums) << endl; 


    return 0 ; 


}