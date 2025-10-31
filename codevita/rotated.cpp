#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<char>> applyGravity(vector<vector<char>> box) {
    int m = box.size();
    int n = box[0].size();
    for (int col = 0; col < n; ++col) {
        int write = m - 1; 
        for (int row = m - 1; row >= 0; --row) {
            if (box[row][col] == '*') {
                if (row != write) {
                    box[write][col] = '*';
                    box[row][col] = '.';
                }
                write--;
            }
        }
      
        for (int r = write; r >= 0; --r) box[r][col] = '.';
    }
    return box;
}

vector<vector<char>> rotateRight(const vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> rotated(n, vector<char>(m, '.'));
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            rotated[j][m - 1 - i] = box[i][j];
    return rotated;
}

vector<vector<char>> rotateLeft(const vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> rotated(n, vector<char>(m, '.'));
    // left rotation mapping: rotated[n-1-j][i] = box[i][j]
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            rotated[n - 1 - j][i] = box[i][j];
    return rotated;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<char>> box(m, vector<char>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> box[i][j];

    int k; cin >> k;
    vector<string> instr(k);
    for (int i = 0; i < k; ++i) cin >> instr[i];

    box = applyGravity(box);


    for (const string &dir : instr) {
        if (dir == "right") {
            box = rotateRight(box);
            box = applyGravity(box);
        } else if (dir == "left") {
            box = rotateLeft(box);
            box = applyGravity(box);
        } else {
            
        }
    }

  
    for (auto &row : box) {
        for (int j = 0; j < (int)row.size(); ++j) {
            cout << row[j];
            if (j + 1 < (int)row.size()) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
