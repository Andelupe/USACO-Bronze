#include <bits\stdc++.h>

#define ll unsigned long long
using namespace std;

int n,k;
vector<ll> items(n+1, 0);
bool check(vector<ll> lo, ll m, ll k) {

    for (int i = n/2; i < n && items[i] < m; i++) {

    }

    return sum <= k;
}

int main() {

    cin >> n >> k;
    vector<ll> items(n+1,0);
    sort(items.begin(), items.end());

    ll l=0, h=2e9;
    int rslt = 0;

    int median = (n/2);
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }
    while (l+1 < h) {
        ll m = (l + h)/2;

        if (check(m)) l=m;
        else h=m;
        }
    }

    cout << l << "\n";
    
}