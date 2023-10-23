#include <bits/stdc++.h>

using namespace std;


bool sortcol (const vector<string>& v1, const vector<string>& v2) {
    return stoi(v1[0]) < stoi(v2[0]);
}

vector<bool> checkMax(int a, int b, int c) {
    int temp = max(a, max(b, c));
    vector<bool> rslt (3, false);
    if (temp == a) rslt[0] = true;
    if (temp == b) rslt[1] = true;
    if (temp == c) rslt[2] = true;
    return rslt;
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<string>> list (n, vector<string> (3, ""));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
        cin >> list[i][j];
        }
    }
    sort(list.begin(), list.end(), sortcol);

    vector<int> cows (3, 0);
    for (int i = 0; i < 3; i++) {
        cows[i] = 7;
    }
    // 0 = Bessie 1 = Elsie 2 = Mildred
    int change = 0;
    vector<bool> isDisplayed (3, false);
    for (int i = 0; i < n; i++) {
        int temp = stoi(list[i][2]);
        if (list[i][1] == "Bessie") {
            cows[0] += temp;
        }
        else if (list[i][1] == "Elsie") {
            cows[1] += temp;
        } else {
            cows[2] += temp;
        }
        
        vector<bool> testCow = checkMax(cows[0], cows[1], cows[2]);
        bool need = false;
        if (testCow[0] && !isDisplayed[0]) {
            isDisplayed[0] = true;
            need = true;
        }
        if (!testCow[0] && isDisplayed[0]) {
            isDisplayed[0] = false;
            need = true;
        }
        if (testCow[1] && !isDisplayed[1]) {
            isDisplayed[1] = true;
            need = true;
        }
        if (!testCow[1] && isDisplayed[1]) {
            isDisplayed[1] = false;
            need = true;
        }
        if (testCow[2] && !isDisplayed[2]) {
            isDisplayed[2] = true;
            need = true;
        }
        if (!testCow[2] && isDisplayed[2]) {
            isDisplayed[2] = false;
            need = true;
        }

        if (need) change++;
    }

    cout << change;
}