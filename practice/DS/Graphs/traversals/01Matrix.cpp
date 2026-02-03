// 542. 01 Matrix
// Medium
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<pair<int,int>> q;

    // Step 1: push all 0s into queue
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // Step 2: BFS
    while(!q.empty()) {
        int r = q.front().first ; 
        int c = q.front().second ; 
        
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if(dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    vector<vector<int>> ans = updateMatrix(mat);

    for(auto &row : ans) {
        for(int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}


