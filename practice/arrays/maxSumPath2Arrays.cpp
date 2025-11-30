// Given two sorted arrays of distinct integers arr1 and arr2. 
// Each array may have some elements in common with the other array.
// Find the maximum sum of a path from the beginning of any array to the end of any array.
// You can switch from one array to another array only at the common elements.

#include <iostream> 
#include <vector> 
using namespace std ;

int maxPathSum(vector<int> &arr1, vector<int> &arr2){
        int n1 = arr1.size() ; 
        int n2 = arr2.size() ; 
        
        int sum1 = 0 , sum2 = 0 , sum = 0 ;  
        
        int i=0 , j=0 ; 
        
        while( i<n1 && j<n2 ) {
            if( arr1[i] > arr2[j] ) {
                sum2 += arr2[j++] ; 
            } 
            else if( arr1[i] < arr2[j] ){
                sum1 += arr1[i++] ; 
            } 
            else {
                sum += max(sum1 , sum2) + arr1[i] ;  
                sum1 = 0 ;
                sum2 = 0 ; 
                
                i++; 
                j++; 
            }
        }  
        
        while( i<n1 ) {
            sum1 += arr1[i++] ; 
        } 
        while( j<n2 ) {
            sum2 += arr2[j++] ; 
        } 
        
        sum += max(sum1 , sum2) ;  
        
        return sum ;
} 

int main() { 
    vector<int> arr1 = {2,3,7,10,12} ; 
    vector<int> arr2 = {1,5,7,8} ; 
}