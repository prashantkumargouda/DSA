#include <iostream>  
#include <vector> 

using namespace std ; 

void rotate1(vector<int> &nums , int k ){  
    int n = nums.size() ; 

    for(int i=0 ; i<k ; i++ ) {
        int last = nums[n-1] ; 

        for(int j=n-1 ; j>0 ; j--) {
            nums[j] = nums[j-1] ; 
        } 

        nums[0] = last ; 
    } 
} 

vector<int> rotate2(vector<int> &nums , int k ) {
    int n = nums.size() ; 

    vector<int> temp(n) ; 

    for(int i=0 ; i<k ; i++ ){
        temp[i] = nums[n-k+i] ; 
    }  

    for(int i=0 ; i<n-k ; i++) {
        temp[i+k] = nums[i] ;
    }

    return temp ; 
}  

void rotate(vector<int> &nums , int k ) {
    int n = nums.size() ; 

    // 1 2 3 4 5 6 
    // 5 6 1 2 3 4  

    // 6 5 4 3 2 1  

    reverse(nums.begin() , nums.end() ) ;  
    reverse( nums.begin() , nums.begin() + k ) ; 
    reverse( nums.begin() + k , nums.end() ) ;  

} 

int main() {
    int n ;
    cin >> n ;

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ; 
    
    rotate1( nums , 2 )  ; 
    for(int it : nums) {
        cout << it << ' ' ; 
    } 

    cout << endl; 

    return 0 ; 
    
}   