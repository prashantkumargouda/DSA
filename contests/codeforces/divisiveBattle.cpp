#include <iostream>  
#include <vector> 
#include <algorithm> 
#include <set> 

using namespace std ; 

typedef long long ll ; 

ll primeBase(ll t) {
	set<ll> st ;  // using this set to get the distinct prime factors for the number 

	for(int i=2 ; i*i <= t ; i++){
		if( t % i == 0 ) {
			while( t % i == 0 ) {
				st.insert(i) ; 
				t = t / i ; 
			}
		}
	}

	if( t > 1 ) {
		st.insert(t); 
	}  
	if( st.size() > 1 ) {
		return -1 ; 
	} 
	if( st.size() == 0 ) {
		return 1; 
	} 

	return *st.begin() ;
}  

int main() {
	int test ; 
	cin >> test ; 

	while( test-- ) {
		ll n ;
		cin >> n ; 

		vector<ll> v1(n) ; 
		for(auto &it : v1) cin >> it ; 

		if( is_sorted(v1.begin() , v1.end()) ) {
			cout << "Bob" << endl; 
			continue ; 
		}  

		vector<ll> v2 ; 
		for(int i=0 ; i<n ; i++) {
			ll q = primeBase(v1[i]) ; 
			v2.push_back(q) ; 
		} 

		if( *min_element(v2.begin() , v2.end() ) == -1 )  {
			cout << "Alice" << endl; 
			continue ;
		} 

		else if( is_sorted(v2.begin() , v2.end() ) ) {
			cout << "Bob" << endl; 
			continue ; 
		}  

		else{
			cout << "Alice" << endl; 
		}

	}
}