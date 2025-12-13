// Split array into three equal sum segments 
// Input: arr[] = [1, 3, 4, 0, 4]
// Output: [1, 2]
// Explanation: 3 equal sum segments are: arr[0...1], arr[2...2] and arr[3...4] each having sum = 4.


#include <iostream>
#include <vector> 

using namespace std ; 

int findSum(vector<int> &arr , int start , int end) {
    int sum = 0 ; 

    for(int i=start ; i<=end ; i++) { 
        sum += arr[i] ; 
    } 

    return sum ; 
} 

vector<int> findSplit(vector<int> &arr) {
    int n = arr.size() ;    

    
    return {-1, -1} ; 
} 

int main() {

}