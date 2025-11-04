#include <iostream>  
#include <vector> 
#include <unordered_set> 
using namespace std ; 

// two sum problem approach 

int main() { 
    vector<int> nums ; 
     
    int x ; 
    while( cin >> x && x != -1 ) { 
        nums.push_back(x) ; 
    } 

    unordered_set<int> seen ; 

    int target = 2020 ;  

    // using the unordered_set to find complements 

    for(int num : nums) { 
        int complement = target - num ;  

        if( seen.count(complement) ) { //I can also use seen.find(complement) != seen.end() here and here .count() returns the count for the number of values with equal to complement existing in the set for unordered-set it will be 1 as it stores only unique values 
            cout << num * complement << endl;   
            cout << num << " " << complement << endl; 
            break ;
        }

        seen.insert(num) ;
    } 

    return 0 ; 
}