#include <iostream> 
using namespace std ; 

long long digitSum(long long x) {
    long long sum = 0;
    while(x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long x;
        cin >> x;

        long long start = (x + 9) / 10 * 10; // first multiple of 10 ≥ x
        int answer = 0;

        for(int i = 0; i < 10; i++) {   // check next 10 blocks
            long long y = start + i * 10;
            if(y - digitSum(y) == x) {
                answer = 10;
                break;
            }
        }

        cout << answer << endl;
    }
}
