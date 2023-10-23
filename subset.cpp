#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;


int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> set (N, 0);
    ll rslt = 0;
    for (ll i = 0; i < N; i++) {
        cin >> set[i];
    }

    for (ll i = 0; i < (1 << N); i++) {
        vector<ll> first (2^(N/2), 0);
        vector<ll> second (2^(N/2), 0);
        for (ll j = 0; j < N/2; j++) {
            if ((i & (1 << j)) > 0) {
                first.push_back(set[j]);
            }
        }
        for (int ll j = N/2; j < N; j++) {
            if (())
        }

        }
    }
    cout << rslt;
}