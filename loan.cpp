#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long
using namespace std;

ll N, M, K;

bool check(ll X) {
    ll remain = N, remainD = K;

    while (remain > 0 && remainD > 0) {
        ll Y = remain/X;
        if (Y < M) return (remain + M - 1) / M <= (remainD);

        ll days = min(remainD, 1 + (remain - Y * X)/Y);
        remain -= Y * days;
        remainD -= days;
    }

    return remain <= 0;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin >> N >> K >> M;
    ll hi, lo, mid;
    lo = 1, hi = N/M + 1;

    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << endl;
}