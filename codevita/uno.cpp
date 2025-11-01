#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> names(N);
    for (int i = 0; i < N; i++) cin >> names[i];

    vector<int> skill(N);
    for (int i = 0; i < N; i++) cin >> skill[i];

    unordered_map<string, int> idx;
    for (int i = 0; i < N; i++) idx[names[i]] = i;

    int N1; // number of friend pairs
    cin >> N1;
    vector<pair<int, int>> friends;
    for (int i = 0; i < N1; i++) {
        string a, b;
        cin >> a >> b;
        friends.push_back({idx[a], idx[b]});
    }

    int N2; // number of rival pairs
    cin >> N2;
    vector<pair<int, int>> rivals;
    for (int i = 0; i < N2; i++) {
        string a, b;
        cin >> a >> b;
        rivals.push_back({idx[a], idx[b]});
    }

    int limit;
    cin >> limit;

    int best = 0;

    // Bitmask enumeration for all subsets
    long long total_combinations = 1LL << N;
    for (long long mask = 0; mask < total_combinations; mask++) {
        int totalSkill = 0, count = 0;
        bool valid = true;

        for (int i = 0; i < N; i++) {
            if (mask & (1LL << i)) {
                totalSkill += skill[i];
                count++;
            }
        }

        if (totalSkill > limit) continue; // exceeds skill limit

        // Check friend constraints
        for (auto &p : friends) {
            int a = p.first, b = p.second;
            bool inA = mask & (1LL << a);
            bool inB = mask & (1LL << b);
            if (inA != inB) { // one selected, other not
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        // Check rival constraints
        for (auto &p : rivals) {
            int a = p.first, b = p.second;
            bool inA = mask & (1LL << a);
            bool inB = mask & (1LL << b);
            if (inA && inB) { // both selected
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        best = max(best, count);
    }

    cout << best << "\n";
    return 0;
}
