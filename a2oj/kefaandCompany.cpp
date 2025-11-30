#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    vector<pair<long long, long long>> a(n); 
    // a[i].first = money, a[i].second = friendship

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    // Sort by money
    sort(a.begin(), a.end());

    long long maxFriendship = 0;
    long long currentSum = 0;
    int left = 0;

    // Sliding window on sorted array
    for (int right = 0; right < n; right++) {
        // include a[right] in the window
        currentSum += a[right].second;

        // shrink window from the left while condition breaks
        while (a[right].first - a[left].first >= d) {
            currentSum -= a[left].second;
            left++;
        }

        // update answer
        maxFriendship = max(maxFriendship, currentSum);
    }

    cout << maxFriendship << "\n";
    return 0;
}
