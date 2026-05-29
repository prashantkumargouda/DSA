#include <bits/stdc++.h>
using namespace std;

int check(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int x = n % 10;
        sum += x;
        n = n / 10;
    }

    return sum;
}

int minElement(vector<int> &nums)
{
    int ans = INT_MAX ; 

    for(int num : nums){
        string s = to_string(num)  ;         
        int sum = 0 ;  

        for(char c : s) {
            sum += c - '0' ;  
            
            ans = min( ans , sum ); 
        }
    } 

    return ans ; 
}  

int main(){
    vector<int> arr = {10 , 20 , 30 , 40} ;  
    cout << minElement(arr) << endl; 

    return 0 ; 
}

