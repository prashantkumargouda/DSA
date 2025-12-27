// learning about a priority queue 

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std ; 

int main() { 
    // okay toh isme min heap aur max heap hota hai  

    // yeh tha apna max heap 
    // yahan pe saare values 
    // descending mai store hote hai 
    // no matter the push type 

    priority_queue<int , vector<int>> pq ; 

    pq.push(10) ; 
    pq.push(100) ; 
    pq.push(20) ; 
    pq.push(30) ;

    // pq.pop() ; 
    // pq.pop() ; 
    // cout << pq.top() << endl;  

    // ab try karenge ek min heap 

    priority_queue<int , vector<int> , greater<int>> pq1 ; 
    pq1.push(10) ; 
    pq1.push(100) ; 
    pq1.push(20) ; 
    pq1.push(30) ;

    pq1.pop() ; 
    cout << pq1.top() << endl;   

    // ab try karenge with a pair  

    priority_queue<pair<int , int> , vector<pair<int , int>> > pq2 ; 

    pq2.push({10, 1});
    pq2.push({20, 2});
    pq2.push({15, 3}); 

    pq2.top() ;  

    return 0 ; 
}