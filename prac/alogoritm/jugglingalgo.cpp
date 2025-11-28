// juggling algorithm to rotate arrays O(n) O(1) 

#include <iostream> 
#include <vector>  
#include <algorithm> 
#include <numeric> 

using namespace std ; 

int gcd(int a, int b) { 
    // helper function for gcd  
    if( b==0 ) return a ; 
    else { 
        gcd(b, a%b) ; 
    }
} 

void rotateArray(vector<int> &arr , int d) {
    int n = arr.size();  

    d = d % n ; 

    int cycles = gcd(n , d) ;

    for(int i=0 ; i<cycles ; i++) { 
        int currIndex = i ; 
        int currElement = arr[currIndex] ; 

        do{  
            int nextIndex = ( currIndex + d ) % n ;  

            int nextElement = arr[nextIndex] ; 
            
            arr[nextIndex] = currElement ;  
            currElement = nextElement ; 
            currIndex = nextIndex ; 

        }while( currIndex != i ) ; 
    }
} 
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int d = 2;

    rotateArray(arr, d);

    // Print the rotated vector
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}