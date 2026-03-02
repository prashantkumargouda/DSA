// printing the subsequences where the sum is K 
// using the pick and not pick method again 

#include <iostream> 
#include <vector> 
using namespace std ; 

// ind to check the level 
// sum given in the problem 
// s current sum 
// n is the number of elements in the arr 

void printS(int ind , vector<int> &ds ,vector<int> &arr, int sum , int s , int n ) {
	if( ind == n ) { 
        if( sum == s ) {
            for(auto &it : ds) {
                cout << it << " " ; 
            } 
            cout << endl; 
        }
        return ; 
	} 

	ds.push_back(arr[ind]) ; 
    s += arr[ind] ; 

    printS( ind + 1 , ds , arr , sum , s , n ) ; 

    ds.pop_back() ; 
    s -= arr[ind] ; 

    printS(ind+1 , ds , arr, sum , s , n ) ; 

}

int main() {
	vector<int> arr = {1,2,1} ;  
	int sum = 2 ; 
	vector<int> ds ; 
	printS(0 , ds ,arr, sum , 0 , 3 ) ; 

	return 0 ; 
}