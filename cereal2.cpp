#include <bits/stdc++.h>

using namespace std;


void dfs() {

}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> cereal;
    vector<int> adjPrefer[M];
    vector<int> adjIn[N];
    cereal.resize(N);
    int rslt = 0;
    vector<bool> visited(M, 0);

    for (int i = 0; i < N; i++) {
        cin >> cereal[i].first >> cereal[i].second;
        cereal[i].first--;
        cereal[i].second--;
        adjPrefer[cereal[i].first].push_back(i);
        adjPrefer[cereal[i].second].push_back(i);
        adjIn[i].push_back(cereal[i].first);
        adjIn[i].push_back(cereal[i].second);

    }

    for (int i = 0; i < M; i++) {
        if (adjPrefer[i].size() > 2) {
            for (int j = 0; j < adjPrefer[i].size(); j++) {
                if (visited[adjPrefer[i][j]]) continue;
                vector<bool> sweep (M, false);
                sweep[i] = true;
                for (int k = 0; k < adjIn[adjPrefer[i][j]].size(); k++) {
                    int temp = adjIn[adjPrefer[i][j]][k];
                    if (sweep[adjIn[adjPrefer[i][j]][k]]) continue;
                    if (adjPrefer[adjIn[adjPrefer[i][j]][k]].size() > 2) {
                        rslt++;
                        visited[adjPrefer[i][j]] = true;
                        break;
                    }
                }
            }
        }
    }

    cout << rslt << "\n";

    vector<int> s (N, -1);
    int index = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            s[index] = i + 1;
            index++;
        } else {
            cout << i + 1 << "\n";
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == -1) break;
        cout << s[i] << "\n";
    }
}