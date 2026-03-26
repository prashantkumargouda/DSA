#include <iostream>  
#include <vector> 

using namespace std ; 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> nums(n) ; 
    for(auto &it : nums) cin >> it ; 

    
    return 0 ; 
}