#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> pSum(n);
    int sum = 0;
    int rslt = INT8_MIN;
    for (int i = 0; i < n; i ++ ) {
        cin >> nums[i];
        sum = nums[i] + sum;
        pSum[i] = sum;
        rslt = max(rslt, pSum[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int temp = pSum[i] - pSum[j];
            rslt = max(rslt, temp);
        }
    }

    cout << rslt;
}