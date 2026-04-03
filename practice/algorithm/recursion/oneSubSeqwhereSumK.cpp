// this is another kind of pattern which arises in recursion 
// of only printing one of the solutions out of all 

#include <iostream> 
#include <vector> 

using namespace std ;

bool printS(int ind , vector<int> &ds ,vector<int> &arr, int sum , int s , int n ) {
	if( ind == n ) { 
        if( sum == s ) {
            for(auto &it : ds) {
                cout << it << " " ; 
            } 
            cout << endl;  
            return true ; 
        } 

        return false ; 
	} 

	ds.push_back(arr[ind]) ; 
    s += arr[ind] ; 

    if( printS( ind + 1 , ds , arr , sum , s , n ) ) return true ; 

    ds.pop_back() ; 
    s -= arr[ind] ; 

    if ( printS(ind+1 , ds , arr, sum , s , n ) ) return true ; 

    return false ; 
}

int main() {
	vector<int> arr = {1,2,1} ;  
	int sum = 2 ; 
	vector<int> ds ; 
	printS(0 , ds ,arr, sum , 0 , 3 ) ; 

	return 0 ; 
}