// Happy Numbers 

#include <bits/stdc++.h> 
using namespace std ; 

int getNext(int n) {
    int sum = 0 ; 
    
    while( n != 0 ) {
        n = n % 10  ; 
        sum += n * n ; 
        n = n / 10 ; 
    } 

    return sum ; 
} 

bool isHappy1(int n) {
    unordered_set<int> seen ; 

    while( n != 1 && !seen.count(n) ) {
        seen.insert(n) ; 
        n = getNext(n) ; 
    } 

    return n == 1; 
} 

bool isHappy(int n) { 
    int slow = n ; 
    int fast = n ; 

    do{ 
        slow = getNext(n) ; 
        fast = getNext(getNext(n)) ; 
    }while( slow != fast ) ;  
    
    return n == 1 ; 
}