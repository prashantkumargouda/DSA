#include <iostream> 
#include <vector> 
// random change
using namespace std ;

int f(int n , vector<int> &dp) {
	if( n<=1 ) return n ; 

	if( dp[n] != -1 ) return dp[n] ; 

	return dp[n] = f(n-1 , dp) + f(n-2 , dp) ; 
} 

int main(){
	int n ; 
	cin >> n ; 

	// dp initialized with values -1 
	vector<int> dp( n+1 , -1 );  
	 
	cout << f(n , dp) ; 
	cout << endl;  

	return 0 ; 
}
