#include <bits/stdc++.h>

using namespace std;

struct shoe {
    int maxDepth, maxStep;
};

vector<int> depth;
vector<shoe> shoes;
bool visited[250][250]; 
int N, B;
int best = 9999;

void dfs(int index, int boot) {
    if (visited[index][boot]) return;
    visited[index][boot] = true;

    if (index == N - 1) {
        best = min(best, boot);
        return;
    }
    
    for (int i = index + 1; i < N && i < shoes[boot].maxStep; i++) {
        if (depth[i] <= shoes[boot].maxDepth) dfs(i, boot);
    }

    for (int i = boot + 1; i < B; i++) {
        if (depth[i] <= shoes[boot].maxDepth) dfs(index, i);
    }
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> N >> B;
    depth.resize(N);
    shoes.resize(B);

    for (int i = 0; i < N; i++) {
        cin >> depth[i];
    }
    for (int i = 0; i < B; i++) {
        shoe temp;
        cin >> temp.maxDepth >> temp.maxStep;
        shoes[i] = temp;
    }
    dfs(0, 0);
    cout << best << "\n";
}