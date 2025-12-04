#include <iostream> 
#include <vector> 
#include <unordered_map> 
using namespace std ;

int findExtra(vector<int> &arr1 , vector<int> &arr2 ) {
    int n1 = arr1.size() ; 
    int n2 = arr2.size() ; 

    unordered_map<int , int> hash ; 
    for(int i=0 ; i<n1 ; i++) {
        hash[arr1[i]] = 0 ; 
    } 

    for(int i=0 ; i<n2 ; i++) {
        hash[arr2[i]]++; 
    } 
    int val ; 
    for(auto p : hash ) {
        if( p.second == 0 ) {
            val = p.first ; 
        }
    } 

    for(int i=0 ; i<n1 ; i++){
        if( arr1[i] == val ) {
            return i ; 
        }
    }
}
int main() {
    vector<int> arr1 = {2,4,6,8,9,10,12} ; 
    vector<int> arr2 = {2,4,6,8,10,12} ; 


    cout << findExtra(arr1 , arr2) << endl ; 

    return 0 ; 

}