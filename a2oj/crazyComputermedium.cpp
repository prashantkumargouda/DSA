#include <iostream> 
#include <vector> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c;
    int k;
    if (!(cin >> n >> c >> k)) return 0;

    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int left = 0;       // left index of current window
    int badCount = 0;   // number of gaps > c in current window
    int ans = 1;        // at least one word if n >= 1

    for (int right = 1; right < n; right++) {
        // Check the new gap introduced by including t[right]
        if (t[right] - t[right - 1] > c) {
            badCount++;
        }

        // Shrink window from the left while it has more than k bad gaps
        while (badCount > k && left < right) {
            if (t[left + 1] - t[left] > c) {
                badCount--;
            }
            left++;
        }

        // Update maximum valid window length
        ans = max(ans, right - left + 1);
    }

    cout << ans << "\n";
    return 0;
}

