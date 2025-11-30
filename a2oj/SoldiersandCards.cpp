
// soldiers and cards 

#include <iostream> 
#include <deque> 
#include <set> 
#include <vector> 

using namespace std ; 

int main() { 
    int n  ; 
    cin >> n ; 

    int k1 , k2 ; 
    cin >> k1 ; 

    deque<int> p1 , p2 ; 

    for(int i=0 ;i<k1 ; i++) {
        int x ; 
        cin >> x ; 
        p1.push_back(x) ;
    } 
    cin >> k2 ; 

    for(int i=0 ; i<k2 ; i++) {
        int x ; 
        cin >> x ; 
        p2.push_back(x) ; 
    } 

    int rounds = 0 ; 

    // record the visited states for the problem 

    set<pair<vector<int> , vector<int> >> seen ; 

    while( !p1.empty() && !p2.empty() ) { 
        vector<int> s1(p1.begin() , p1.end() ) ;  
        vector<int> s2(p2.begin() , p2.end() ) ;  

        pair<vector<int> , vector<int> > state = {s1 , s2} ;  
        
        if( seen.count(state) ) { 
            // if already visited state then 
            cout << "-1" << endl; 
            return 0 ;  
        } 

        seen.insert(state) ; 

        int c1 = p1.front() ; 
        p1.pop_front() ; 
        int c2 = p2.front() ; 
        p2.pop_front() ; 

        if( c1 > c2 ) {   // move the values from one to another 
            p1.push_back(c2) ; 
            p1.push_back(c1) ; 
        }else { 
            p2.push_back(c1) ;
            p2.push_back(c2) ; 
        } 

        ++rounds ; 
    }  

    // now simply print the winner and rounds  

    if( p1.empty() ) { 
        cout << rounds << " " << "2" << endl; 
    } else { 
        cout << rounds << " " << "1" << endl; 
    } 

    return 0 ; 

}