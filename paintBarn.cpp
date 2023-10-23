#include <bits\stdc++.h>

using namespace std;
    int nums[1001][1001] = {0};
    int prefix[1001][1001] = {0};

int main() {
    freopen("paintBarn.in", "r", stdin);
    freopen("paintBarn.out", "w", stdout);
    int k, n;
    cin >> n >> k;
    int rslt;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        nums[x1+1][y1+1]++;
        nums[x2+1][y2+1]++;
        nums[x1+1][y2+1]--;
        nums[x2+1][y1+1]--;
    }
    for (int i = 1; i < 1003; i++) {
        for (int j = 1; j < 1003; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + nums[i][j];
        }
    }

    for (int i = 0; i < 1003; i++) {
        for (int j = 0; j < 1003; j++) {
            if (prefix[i][j] == k) rslt++;
        }
    }

    cout << rslt;
}