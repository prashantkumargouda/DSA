#include <iostream> 
using namespace std ;

typedef long long ll ; 

long long countComma(ll n) {
    ll count = 0; 
    ll threshold = 1000 ; 

    while( threshold <= n ) {
        count += n - threshold + 1 ; 
        threshold *= 1000 ; 
    } 

    return count ; 

}
int main() {
    ll n ;
    cin >> n ; 

    cout << countComma(n) << endl; 

    return 0 ;

}