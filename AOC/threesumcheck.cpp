#include <iostream>
#include <vector>
#include <unordered_set> 

using namespace std ; 

void triplets( vector<int> nums , int n , int target ) { 
    unordered_set<int> seen ;  

    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++){ 
            int sum = nums[i] + nums[j] ; 
            int third = target - sum ; 
            
            if( seen.count(third) ) { 
                cout << nums[i] << " " <<nums[j] << " " << third << endl; 
                cout <<  nums[i] * nums[j] * third << endl; 
                break ; 
            } 
        } 
        seen.insert(nums[i]) ; 
    }
} 

int main() { 
    vector<int> nums ; 

    int x ; 
    while( cin >> x && x != -1 ) { 
        nums.push_back(x) ; 
    }   

    int target = 2020 ; 
    cout << endl; 
    triplets( nums , nums.size() , target )  ; 

    return 0 ; 
    

}