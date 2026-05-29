#include <bits/stdc++.h> 
using namespace std ; 

vector<int> bucketSort(vector<int> &nums){
    int n = nums.size() ; 
    
    vector<vector<int>> buckets(10) ; 

    int maxi = *max_element(nums.begin() , nums.end() ) ; 
    for(int n : nums) {
        int ind = ( n * 10 ) / ( maxi + 1 ) ; 
        buckets[ind].push_back(n) ; 
    }   

    for(auto& bucket : buckets) {
        sort( bucket.begin() , bucket.end() ) ; 
    } 

    int k=0 ; 

    for(auto &bucket : buckets) {
        for(int x: bucket) {
            nums[k++] = x ; 
        }
    } 

    return nums; 
} 

int main() {
    vector<int> arr = {3 , 6 , 9 ,1} ; 
    vector<int> temp = bucketSort(arr) ; 
    for(int x : temp) {
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}