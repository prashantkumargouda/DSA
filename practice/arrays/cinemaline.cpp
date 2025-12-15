#include <iostream>
#include <vector> 

using namespace std ; 

int main() {
    int n ; 
    cin >> n ; 

    int count25 = 0 , count50 = 0 ; 

    for(int i=0 ; i<n ; i++) {
        int bill ; 
        cin >> bill ; 

        if( bill == 25 ) {
            count25++ ;
        } 
        else if( bill == 50 ) {
            if( count25 > 0 ) { 
                count50++ ; // increasing the 50 count in the wallet 
                count25-- ; // and reducing the 25 count in the wallet 
            }else{
                cout << "NO" << endl; 
                return 0 ;
            }
        } 
        else { // for bills of 100  
            if( count50 > 0 && count25 > 0 ){
                count50-- ; 
                count25-- ; 
            } 
            else if( count25 >= 3 ) {
                count25 = count25 - 3  ; 
            }else {
                cout << "NO" << endl; 
                return 0 ; 
            }
        }
    } 

    cout << "YES" << endl; 

    return 0 ; 
}