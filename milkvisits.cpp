#include <bits/stdc++.h>

using namespace std;

struct person {
    int start, end;
    char type;
};

string length;
vector<vector<int>> adj;
vector<person> testCase;
vector<int> comp;

void floodfill(int node, int index, char prev) {
    if (comp[node] != -1) return;
    if (prev == length[node]) {
        comp[node] = index;
    } else {
        prev = length[node];
        index++;
        comp[index];
    }

    for (int i = 0; i < adj[node].size(); i++) {
        floodfill(adj[node][i], index, length[node]);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M;
    cin >> N >> M >> length;
    adj.resize(N);
    testCase.resize(M);
    comp.resize(N);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        comp[i] = -1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < M; i++) {
        person temp;
        int a, b;
        a--; b--;
        char c;
        cin >> a >> b >> c;
        temp.start = a; temp.end = b;
        testCase[i] = temp;
    }

    int index = 0;
    floodfill(0, index, length[0]);

    string rslt = "";
    for (int i = 0; i < M; i++) {
        if (comp[testCase[i].start] == comp[testCase[i].end] && testCase[i].type == length[testCase[i].start]) {
            rslt += "1";
        } else if (comp[testCase[i].start] != comp[testCase[i].end]) {
            rslt += "1";
        } else rslt += "0";
    }

    cout << rslt << "\n";
}