#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vector<int> capacity (3, 0);
    vector<int> milk (3, 0);
    for (int i = 0; i < 3; i++) {
        cin >> capacity[i] >> milk[i];
    }

    int index = 0;
    int index2 = 1;
    for (int i = 0; i < 100; i++) {
        if (index == 2) index2 = 0;
        if (index == 3) index = 0;

        int add = min((capacity[index2] - milk[index2]), milk[index]);
        milk[index2] += add;
        milk[index] -= add;
        index++;
        index2++;
    }

    for (int i = 0; i < 3; i++) {
        if (i == 2) {
            cout << milk[i];
            break;
        }
        cout << milk[i] << "\n";
    }
}