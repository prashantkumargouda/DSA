#include <iostream> 
using namespace std ;

int main(){
    int n ;
    cin >> n ;

    int prev = 1 ; 
    int prev2 = 0 ; 

    for(int i=2 ; i<=n ; i++) {
        int curri = prev + prev2 ;
        prev2 = prev ; 
        prev = curri ; 
    } 

    cout << prev << endl;  

    return 0 ; 
}