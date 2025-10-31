#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Race {
    int x, y, t;
};

int manhattan(const Race &a, const Race &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool canReach(const Race &a, const Race &b) {
    return manhattan(a, b) <= (b.t - a.t);
}

bool dfs(int u, vector<vector<int>> &adj, vector<int> &match, vector<bool> &visited) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || dfs(match[v], adj, match, visited)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int minCarsRequired(vector<Race> &races) {
    int n = races.size();
    // Sort races by time
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (races[i].t > races[j].t)
                swap(races[i], races[j]);
        }
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (canReach(races[i], races[j])) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> match(n, -1);
    int maxMatching = 0;

    for (int u = 0; u < n; ++u) {
        vector<bool> visited(n, false);
        if (dfs(u, adj, match, visited)) {
            maxMatching++;
        }
    }

    return n - maxMatching;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Race> races(n);
    for (int i = 0; i < n; ++i) {
        cin >> races[i].x >> races[i].y >> races[i].t;
    }

    cout << minCarsRequired(races) << "\n";
    return 0;
}
