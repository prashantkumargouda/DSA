#include <iostream> 
#include <vector> 
#include <numeric> 

using namespace std ; 

// the problem is to find : 
// the last player who is going to play the move 
// and then check if it is non decreasing or not 
// if it is non decreasing bob wins  
// if not alice wins 

// now the question is about how are we going to count the no of moves to find the last move to be taken 
// we do that by finding the smallest prime numbers for all the elements in the array 

// so we pre calculate the primes for these numbers 

const int MAXV = 1e6 + 5 ;
int spf[MAXV] ; 

void seive() {
	// use the iota to mark all the values in array spf 
	iota(spf , spf + MAXV , 0) ;  

	// now starting with 2 
	for(int i=2 ; i*i < MAXV ; i++) {
		if( spf[i] == i ) {
			for(int j=i*i ; j<MAXV ; j+=i) {
				if( spf[j] == j ) spf[j] = i ; 
			}
		}
	}
} 

int countMoves(int x) {
	int count = 0 ; 
	while( x>1 ) {
		x = x / spf[x] ;  
		count++ ; 
	}

	return count ; 
} 

int main(){  

    seive() ; 

	int t ; 
	cin >> t ; 

	while( t-- ) {
		int n ; 
		cin >> n ; 

		vector<int> a(n) ; 
		for(auto& x: a) cin >> x ;   
   		
   		// alice wins if : it is not non decreasing( decreasing or zigzag( depending upon turns )) 
   		// bob wins if : it is non decreasing( increasing or zigzag ) 


		// checking if a is already sorted 
		bool sorted = true ;

		for(int i=0 ; i<n-1; i++) {
			if( a[i] > a[i+1] ) { sorted = false ; break; } 
		} 
 
 		if( sorted ) {
 			cout << "Bob" << endl; 
 			continue ; 
 		} 

 		long long moves = 0 ; 

 		for(int x : a) moves += max( 0 , countMoves(x) - 1 ) ; 

 		cout << ((moves % 2 == 1) ? "Alice" : "Bob") ; 

 		cout << endl; 
	}
}