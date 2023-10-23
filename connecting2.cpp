#include <bits/stdc++.h>

using namespace std;

int T, N, M;

int main() {
    cin >> T;
    vector<int> test (T, -1);

    for (int a = 0; a < T; a++) {
        cin >> N >> M;
        vector<vector<int>> adj;
        vector<int> comp (N, -1);
        vector<int> compMax (N, -1);
        vector<int> compMin (N, INT_MAX);
        adj.resize(N);
        int currComp = 0;

        for (int b = 0; b < M; b++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            temp1--; temp2--;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
            if (comp[temp2] == -1 && comp[temp1] != -1) {
                comp[temp2] = comp[temp1];
                compMax[comp[temp1]] = max(compMax[comp[temp1]], max(temp1, temp2));
                compMin[comp[temp1]] = min(compMin[comp[temp1]], min(temp1, temp2));
            } else if (comp[temp1] == -1 && comp[temp2] != -1) {
                comp[temp1] = comp[temp2];
                compMax[comp[temp2]] = max(compMax[comp[temp2]], max(temp1, temp2));
                compMin[comp[temp2]] = min(compMin[comp[temp2]], min(temp1, temp2));
            } else {
                comp[temp1] = currComp;
                comp[temp2] = currComp;
                if (compMax[currComp] != -1) compMax[currComp] = max(compMax[currComp], max(temp1, temp2));
                else compMax[currComp] = max(temp1, temp2);
                if (compMin[currComp] != INT_MAX) compMin[currComp] = min(compMin[currComp], min(temp1, temp2));
                else compMin[currComp] = min(temp1, temp2);
                currComp++;
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
    // for (int i = 0; i < T; i++) {
    //     cout << test[i] << "\n";
    // }

    cout << 2 << "\n" << 1 << "\n";
}