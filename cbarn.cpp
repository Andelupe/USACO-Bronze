#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> cows(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }

    int rslt = INT_MAX;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            temp += (cows[j] * (N - i + j));
        }
        for (int k = N - 1; k > i; k--) {
            temp += (cows[k] * (k - i));
        }
        rslt = min(rslt, temp);
    }

    cout << rslt << endl;
}