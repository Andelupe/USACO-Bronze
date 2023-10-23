#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> clockValue, workSet;
int N;

void dfs(int k, int p) {
    for (auto v: adj[k])
        if (v != p) dfs(v, k);
    if (p >= 0) workSet[p] = (workSet[p] + 12 - workSet[k])%12;
}
int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    cin >> N;
    clockValue.resize(N);
    adj.resize(N);
    
    for (int i = 0; i < N; i++) {cin >> clockValue[i];}
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int rslt = 0;
    for (int i = 0; i < N; i++) {
        workSet = clockValue;
        dfs(i, -1);
        if (workSet[i] == 1 || workSet[i] == 0) rslt++;
    }

    cout << rslt << "\n";
}