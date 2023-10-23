#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll N, rslt = 0;
    string s;
    cin >> N >> s;
    vector<ll> g (N, 0), h(N, 0);
    for (ll i = 0; i < N; i++) {
        if (i == 0) {
            if (s[i] == 'G') g[i]++;
            else h[i]++;
            continue;
        }
        if (s[i] == 'G') {
            g[i] = g[i - 1] + 1;
            h[i] = h[i - 1];
        }
        else {
            g[i] = g[i - 1];
            h[i] = h[i - 1] + 1;
        }
    }
    for (int i = -1; i < N; i++) {
        for (int j = 3; j < N - i; j++) {
            if (i == -1) {
                if (g[i + j] == 1 || h[i + j] == 1) rslt++;
                continue;
            }
            if (g[i + j] - g[i] > 1 && h[i + j] - h[i] > 1) break;
            if ((g[i + j] - g[i]) == 1 || (h[i + j] - h[i]) == 1) rslt++;
        }
    }
    cout << rslt << "\n";
}