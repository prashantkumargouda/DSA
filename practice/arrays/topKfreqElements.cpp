#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include <algorithm> 
#include <queue> 

using namespace std ; 

// use an unoredered_map 
// to store the counts 
// then use a vector pair to sort it 
// and show the first K values 

vector<int> findK(vector<int> &arr , int k) {
    int n = arr.size() ; 

    unordered_map<int , int> mp ; 

    for(int num : arr) {
        mp[num]++ ; 
    } 

    vector<pair<int , int>> pq( mp.begin() , mp.end() ) ;  
    
    sort(pq.begin() , pq.end() , 
    [](const pair<int,int> &a , const pair<int,int> &b) {
        return a.second > b.second ; 
    }) ; 

    vector<int> ret ; 

    for(int i=0 ; i<k && i<pq.size() ; i++ ) {
        ret.push_back(pq[i].first) ; 
    }    

    return ret ; 
    
} 

vector<int> findK2(vector<int> &nums ,int k ) {
    // using a priority queue 

    int n = nums.size() ; 

    unordered_map<int , int> mp ; 

    for(int num : nums) {
        mp[num]++;  
    } 

    priority_queue< pair<int , int> , vector<pair<int, int>> > pq ; 

    for( auto &p : mp ) {
        pq.push( { p.second , p.first } ) ; 
    } 

    vector<int> res ; 

    for(int i=0 ; i<k ; i++) {
        res.push_back(pq.top().second) ; 
        pq.pop() ; 
    }

    return res ; 
}
int main(){
    vector<int> arr = {1,1,1,1,2,2,3,3,3,3,3} ; 

    vector<int> temp = findK(arr , 2) ; 

    for(int x : temp) {
        cout << x << " " ; 
    } 

    cout << endl; 
    
    vector<int> temp2 = findK2( arr , 2 ) ; 

    for(int x : temp2 ) {
        cout << x << " " ; 
    } 

    cout << endl; 

    return 0 ; 
}   