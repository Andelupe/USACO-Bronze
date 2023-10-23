#include <bits/stdc++.h>

using namespace std;

int N, M, label;
vector<int> numbers, component;

struct Edge{int d, w;};
vector< vector<Edge> > adj;


void dfs(int n, int w) {
    if (component[n] != -1) return;
    component[n] = label;
    for (auto v: adj[n])
        if(v.w >= w) dfs(v.d, w);
}
bool isokay (int w) {
    fill(component.begin(), component.end(), - 1);
    label = 0;
    for (int i = 0; i < N; i++) {
        if (component[i] == -1) {
            label++;
            dfs(i, w);
        }
    }

    for (int i = 0; i < N; i++) 
        if (component[i] != component[numbers[i]])
            return false;
    return true;
}



int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    cin >> N >> M;
    numbers.resize(N);
    adj.resize(N);
    component.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        numbers[i]--;
    }
    for (int i = 0; i < M; i++) {
        int s, e, w; cin >> s >> e >> w;
        s--; e--;
        adj[s].push_back({e, w});
        adj[e].push_back({s, w});
    }

    int l = 0, h = 1e9 + 1;
    if (isokay(h)) {cout << -1 << "\n"; return 0;}
    while (l+1 < h) {
        int mid = (l+h)/2;
        if (isokay(mid))l = mid;
        else h = mid;
    }

    cout << l << "\n";
}