#include <bits/stdc++.h>

using namespace std;

int T, N, K, rslt = 0;

void dfs (int N, int K, int X, int Y, char d, int change, vector<string> grid, vector<vector<bool>> &visited, bool unique) {
    if (X >= N || Y >= N || change > K) return;
    if (grid[Y][X] == 'H') return;
    if (X == N - 1 && Y == N - 1 && unique) {
        rslt++;
        unique = false;
        return;
    }
    if (visited[X][Y] == false) unique = true;
    visited[X][Y] = true;

    if (d == 'D') {
        dfs(N, K, X, Y + 1, 'D', change, grid, visited, unique);
        dfs(N, K, X + 1, Y, 'R', change + 1, grid, visited, unique);
    } else {
        dfs(N, K, X, Y + 1, 'D', change + 1, grid, visited, unique);
        dfs(N, K, X + 1, Y, 'R', change, grid, visited, unique);
    }
}

int main() {
    cin >> T;
    vector<int> test(T, 0);
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        rslt = 0;
        vector<string> list(N, "");
        vector<vector<bool>> visited(N, vector<bool> (N, false));
        for (int j = 0; j < N; j++) {
            cin >> list[j];
        }
        dfs(N, K, 0, 1, 'D', 0, list, visited, false);
        dfs(N, K, 1, 0, 'R', 0, list, visited, false);
        test[i] = rslt;
        }
    }
    for (int i = 0; i < T; i++) {
        cout << test[i] << "\n";
    }
}