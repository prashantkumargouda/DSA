#include <iostream> 
#include <vector> 

using namespace std; 

void moveZeroes1(vector<int> &nums) {
    int n = nums.size()  ; 

    
} 
void moveZeroes(vector<int> &nums) {
    int n = nums.size() ; 
    
    int count = 0 ; 
    
    for(int i=0 ; i<n ; i++) {
        if( nums[i] != 0 ) {
            nums[count++] = nums[i] ; 
        }   
    } 

    while( count < n ) {
        nums[count++] = 0 ; 
    } 
}  

int main() {
    int n ;
    cin >> n ; 

    vector<int> arr(n) ; 
    for(auto &it : arr) cin >> it ; 

    moveZeroes(arr) ; 

    for(int i : arr) cout << i << " " ; 

    cout << endl; 

    return 0 ; 
}