#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> deleted;

void dfs(int curr, int &check) {
    if (visited[curr] || deleted[curr]) return;
    visited[curr] = true;
    check++;
    for (int i = 0; i < adj[curr].size(); i++) {
        dfs(adj[curr][i], check);
    }
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    
    adj.resize(n);
    visited.resize(n);
    deleted.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int check = 0;
    int want = n;
    dfs(0, check);
    if (check == want) cout << "YES" << endl;
    else cout << "NO" << endl;
    vector<int> intDel;
    intDel.resize(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        temp--;
        intDel[i] = temp;
    }

    for (int i = 0; i < n - 1; i++) {
        deleted[intDel[i]] = true;
        fill(visited.begin(), visited.end(), false);
        want--;
        check = 0;
        dfs (intDel[n - 1], check);
        if (check == want) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}