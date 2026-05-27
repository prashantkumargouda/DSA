#include <bits/stdc++.h> 
using namespace std ; 

bool f(int k , vector<int> &arr) { 
	vector<int> prev(k+1 , 0)  ; 
	prev[0] = true ; 
	int n = arr.size() ; 

	if( arr[0] <= k ) {
		prev[arr[0]] = true ; 
	} 

	for(int i=1 ; i<n ; i++) {
		vector<int> curr(k+1 , 0); 	
		curr[0] = true ;  
		for(int j=1 ; j<=k ; j++) {
			bool notTake = prev[j] ; 
			bool take = false ; 

			if( arr[i] <= j ) {
				take = prev[j-arr[i]] ; 
			} 

			curr[j] = take || notTake ; 
		} 

		prev = curr ; 
	} 

	return prev[k] ; 
}

bool canPartition(vector<int> &arr, int n)
{
	int sum = accumulate(arr.begin() , arr.end() , 0)  ; 
	if( sum % 2 != 0 ) return false ; 
	else {
		int target = sum / 2 ; 
		return f(target , arr) ; 
	} 
} 

