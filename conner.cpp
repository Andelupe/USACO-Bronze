#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

main() {
    int t;
    cin >> t;
    int rslt[t] = {0};
    for (int i = 0; i < t; i++) {
        int n, s, k;
        cin >> n >> s >> k;

        int kNums[k] = {0};


        for (int j = 0; j < k; j++) {          
            cin >> kNums[j];
            
        }

        sort(kNums, kNums + k);
        bool kTest[n] = {false};
        for (int j = 0; j < k; j++) {
            kTest[kNums[j] - 1] = true;
        }
        int bot = -1000;
        int top = -1000;
        int count = -1;
        for (int j = s - 1; j >= 0; j--) {
            count++;
            if (kNums[j] = true) {
                continue;
            } else {
                bot = count;
            }
        }
        count = -1;
        for (int j = s - 1; j < sizeof(kNums); j++) {
            count++;
            if (kNums[j] = true) {
                continue;
            } else {
            top = count;
            }
        }

        if (bot <= count) {
            rslt[i] = bot;
        }
        else {
            rslt[i] = top;
        }
    }

    for (int i = 0; i < t; i++) {
        cout << rslt[i];
    }
}