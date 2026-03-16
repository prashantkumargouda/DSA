#include <iostream>  
#include <string>  
#include <set> 

using namespace std ;  

int main(){
    int t ; 
    cin >> t ;

    while( t-- ) {
        int n ;
        cin >> n ;

        string str ; 
        cin >> str ; 

        set<int> temp ;  
        temp.insert(0) ; 
        int count = 0 ; 

        for(int i=0 ; i<n ; i++){
            if( str[count] == 'R' ) count++ ; 
            else{
                count-- ; 
            } 

            temp.insert(count) ; 
        }

        cout << temp.size() << endl; 
    }
}
