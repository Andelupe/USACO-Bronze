#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll q, k, d, base;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        cin >> k;
        base = 9;
        d = 1;
        while (k > d * base) {
            k -= (d++)*base;
            base *= 10;            
        }
        ll num = (base/9) + k/d;
        ll num2 = k%d;
        if (num2 == 0) {
            num--;
            cout << num%10 << "\n";
        } else {
            string temp = to_string(num);
            char rslt1 = temp[num2];
            cout << rslt1 << "\n";
        }
    }
}