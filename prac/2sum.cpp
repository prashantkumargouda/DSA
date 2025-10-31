// trying out 2sum again with all the brute better optimized solutions 

// trying out the brute solution with O(n ^ 2) tc 

#include <iostream> 
#include <vector> 
using namespace std  ; 


    // vector<int> twoSum(vector<int>& nums, int target) {
    //     // trying out the better method now  

    //     int n = nums.size() ; 
        
    //     unordered_map<int , int> mp ; 

    //     for(int i=0 ; i<n ; i++) { 
    //         int comp = target - nums[i] ;  

    //         if( mp.find(comp) != mp.end() ) { 
    //             return { mp[comp] , i } ; 
    //         } 

    //         mp[nums[i]] = i ;  
    //     } 

    //     return {} ; 
    // }


//     vector<int> twoSum(vector<int>& nums, int target) {
//     vector<pair<int, int>> arr;
//     for (int i = 0; i < nums.size(); i++) {
//         arr.push_back({nums[i], i});
//     }

//     sort(arr.begin(), arr.end());  // sort by value

//     int left = 0, right = arr.size() - 1;

//     while (left < right) {
//         int sum = arr[left].first + arr[right].first;
//         if (sum == target)
//             return {arr[left].second, arr[right].second};
//         else if (sum < target)
//             left++;
//         else
//             right--;
//     }

//     return {};
// }

    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n = nums.size() ;  

    //     vector<int> ans ;  
         
    //     for(int i=0 ; i<n ; i++) { 
    //         for(int j=i+1 ; j<n ; j++ ) { 
    //             if( nums[i] + nums[j] == target ) {
    //                 ans.push_back(i) ; 
    //                 ans.push_back(j) ; 
    //             }
    //         }
    //     } 

    //     return ans; 

        

    // }


