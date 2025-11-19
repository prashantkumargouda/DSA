#include <iostream>
using namespace std ;  

class Node{ 

public : 
    int data ; 
    Node* next = NULL ; 

    Node(int x) { 
        this -> data = x ; 
        this -> next = NULL ;
    } 

    ~Node() { 
        int value = this -> data ; 
        if(this -> next != NULL) { 
            delete next ; 
            this -> next = NULL ; 
        } 

        cout << "memory freed for value " << value << endl;
    }
};  

void display(Node* &head) { 
    Node* temp = head ;

    while( temp != NULL ) { 
        cout << temp -> data << " " ;  
        temp = temp -> next ; 
    } 
    cout << endl; 
} 

void add_back(Node* &head , int data) { 
    // creating the new data 
    Node* newNode = new Node(data) ; 
    Node* temp = head ; 
    while( temp -> next != NULL ) { 
        // reaching the end  
        temp = temp -> next  ; 
    } 
    temp -> next = newNode ; 
}   

// dont need the length function to find the middle of the linked list 
// making use of fast and slow pointers or 2 pointers  

Node* mergeSort(Node* &head) {  
    // single element present 
    if( head == nullptr || head -> next == nullptr ) { 
        return head ; 
    }  

    Node* temp = NULL ; 
    Node* slow = head ;  
    Node* fast = head ;  

    while( fast != NULL && fast -> next != NULL ) {  
        temp = slow ; 
        slow = slow -> next ;  
        fast = fast -> next -> next ; 
    } 

    temp = temp -> next ; // temp = slow -> next  ;  

    Node* l1 = mergeSort(head) ;  // starting node 
    Node* l2 = mergeSort(slow) ;  // passing on the middle value  

    return merge(l1 , l2) ; 
 
} 

Node* merge(Node* &l1 , Node* &l2) { 
    Node* ptr = new Node(0)  ; 
    Node* curr = ptr ;  // assigning zero at the beginning why ?  

    while( l1 != NULL && l2 != NULL ){ 
        if( l1 -> next <= l2 -> next ) { 
            curr -> next = l1 ;  
            l1 = l1 -> next ; 
        } 
        else {  
            curr -> next = l2 ; 
            l2 = l2 -> next ; 
        } 
        curr = curr -> next ; 
    } 

    if( l1 != NULL ) { 
        curr -> next = l1 ; 
    }
    if( l2 != NULL ) { 
        curr -> next = l2 ;
    } 

    return ptr -> next ; 

} 

int main() { 
    Node* head = new Node(10) ; 

}