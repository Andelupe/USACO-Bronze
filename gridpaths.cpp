#include <bits/stdc++.h>


using namespace std;

int N = 7, rslt = 0;
string s = "";
vector<vector<bool>> visited(N, vector<bool>(N, false));


void dfs (int r, int c, char d, int step) {
    if (r < 0 || c < 0 || r >= N || c >= N || visited[r][c]) return;
    if (s[step] != '?' && s[step] != 'd') return;    
    if (r == N - 1 && c == 0 ) {
        rslt++;
        return;
    }
    
    dfs (r + 1, c, 'D', step + 1);
    visited[r + 1][c] = true;
    dfs (r - 1, c, 'U', step + 1);
    visited[r - 1][c] = true;
    dfs (r, c - 1, 'L', step + 1);
    visited[r][c - 1] = true;
    dfs (r, c + 1, 'R', step + 1);
    visited[r][c + 1] = true;

    visited[r][c] = false;
}

int main() {
    cin >> s;
    dfs (0, 1, 'R', 1);
    dfs (1, 0, 'D', 1);

    cout << rslt;
}