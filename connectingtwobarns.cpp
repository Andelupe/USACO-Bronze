#include <bits/stdc++.h>

using namespace std;

int T, N, M;

void check (int index, int &currComp, vector<int> &comp, vector<vector<int>> adj, vector<int> &compMax) {
    if (comp[index] != -1) return;
    else if (adj[index].size() != 0) {
        comp[index] = currComp;
        compMax[currComp] = max(compMax[currComp], index);
    }
    for (int i = 0; i < adj[index].size(); i++) {
        check (adj[index][i], currComp, comp, adj, compMax);
    }
}

int main() {
    cin >> T;
    vector<int> test (T, -1);
    for (int a = 0; a < T; a++) {
        cin >> N >> M;
        vector<vector<int>> adj;
        vector<int> comp (N, -1);
        vector<int> compMax (N, -1);
        vector<int> compMin (N, -1);
        adj.resize(N);
        int currComp = 0;
        for (int b = 0; b < M; b++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            temp1--; temp2--;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
            if (comp[temp1] != -1) comp[temp2] = comp[temp1];
        }

        for (int i = 0; i < N; i++) {
            check (i, currComp, comp, adj, compMax);
            if (i + 1 != N) {
                if (!adj[i + 1].empty() && comp[i + 1] == -1) {
                    currComp++;
                    compMin[currComp] = i + 1;
                }
            }
        }
        if (comp[0] == comp[N - 1]) {
            test[a] = 0;
            continue;
        }
        if (1 == comp[N - 1]) {
            int temp = compMin[1] - compMax[0];
            if (temp % 2 == 0) test[a] = 2 * pow(temp/2, 2);
            else test[a] = pow((temp / 2), 2) + pow((temp / 2) + 1, 2);
        }
    }
    for (int i = 0; i < T; i++) {
        cout << test[i] << "\n";
    }
}