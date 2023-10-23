#include <bits/stdc++.h>

using namespace std;

int n, m, label = 0;
vector<vector<int>> adj;
vector<int> comp;

void dfs(int n, int l) {
    if (comp[n] != -1) return;
    comp[n] = 1;
    for (int neigh : adj[n])
        dfs(neigh, l);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
    cin >> n >> m;
    adj.resize(n); comp.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        c1--; c2--;
        adj[c1].push_back(c2), adj[c2].push_back(c1);
    }

    vector<int> root;
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1) {
            root.push_back(i); dfs(i, label++);
        }
    }

    cout << (label-1) << '\n';
    for (int i = 1; i < label; i++) {
        cout << root[i-1] << ' ' << root[i] << '\n';
    }
}