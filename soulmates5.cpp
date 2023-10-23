#include <bits/stdc++.h>
#define ll long long

using namespace std;
struct cows {
    ll first, second;
};

vector<ll> test;

int main() {
    freopen("soulmates.in", "r", stdin);
    freopen("soulmates.out", "w", stdout);
    vector<cows> list;
    vector<ll> test;
    int N;
    cin >> N;
    list.resize(N);
    test.resize(N);

    for (ll i = 0; i < N; i++) {
        cin >> list[i].first >> list[i].second;

        ll count = 0;
        while (list[i].first > list[i].second) {
            if (list[i].first % 2 == 1) {
                list[i].first++;
                count++;
            }
            list[i].first /= 2;
            count++;
        }

        ll rslt = LONG_LONG_MAX;
        ll S = list[i].second;
        vector<ll> prevS;
        while (S > 0) {
            prevS.push_back(S);
            S = S/2;
        }
        for (ll j = 0; j < prevS.size(); j++) {
            ll testS = list[i].first;
            ll tempR = 0;


            while (testS > prevS[j]) {
                if (testS % 2 == 1) {
                    testS++;
                    count++;
                }
                testS /= 2;
                count++;
            }

            tempR += prevS[j] - testS;
            testS = prevS[j];
            
            
            ll k = j - 1;
            while (testS != list[i].second) {
                testS *= 2;
                tempR++;
                if (testS == prevS[k] - 1) {
                    testS++;
                    tempR++;
                }
                k--;
            }
            rslt = min(rslt, count + tempR);
        }
        test[i] = rslt;
    }

    for (int i = 0; i < N; i++) {
        cout << test[i] << "\n";
    }
}