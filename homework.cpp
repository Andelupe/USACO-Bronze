#include <iostream>
#include <vector>

#define ll unsigned long long
using namespace std;

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    int n; cin >> n;
    vector<ll> s(n+1,0), m(n+1,0), p(n+1,0);

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    
    m[n] = s[n];
    p[n] = s[n];
    for (int i = n - 1; i > 0; i--) {
        m[i] = min(m[i+1], s[i]);
        p[i] = p[i+1] + s[i];
    }

    double bestCase = 0;
    vector<int> rslt;
    for (int k = 1; k < n - 1; k++) {
        double avg = (p[k+1] - m[k+1])/(double)(n-k-1);
        if (avg > bestCase) {
            bestCase = avg;
            rslt.clear();
            rslt.push_back(k);
        }

        else if (avg == bestCase) rslt.push_back(k);
    }

    for (int i: rslt) {
        cout << i << "\n";
    }

}