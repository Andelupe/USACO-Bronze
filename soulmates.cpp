#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct cows {
    ll first, second;
};

vector<ll> test;
ll rslt = 0;


void dfs2(ll first, ll second, int count) {
    if (first == second) {
        rslt = count;
        return;
    }
    if (first > second) {
        if (first % 2 == 0) {
            dfs2(first/2, second, count + 1);
            return;
        } else {
            dfs2(first + 1, second, count + 1);
            return;
        }
    }

    if ((first + 1) * 2 <= second) {
        dfs2(first + 1, second, count + 1);
        return;
    } else {
        if (first * 2 == second || first * 2 == second - 1) {
            dfs2(first * 2, second, count + 1);
            return;
        }
        if (first + 1 == second) {
            dfs2(first + 1, second, count + 1);
            return;
        }
        if (second % 2 == 0) {
            ll tempS = second/2;

            if (first % 2 == 0) {
                if (tempS < first/2) {
                    dfs2(first + 1, second, count + 1);
                    return;
                }
                if (((tempS - first/2) + 2) < second - first) {
                    dfs2(first/2, second, count + 1);
                    return;
                } else {
                    dfs2(first + 1, second, count + 1);
                    return;
                }
            } else {
                dfs2(first + 1, second, count + 1);
                return;
            }
                
        } else {
            ll tempS = (second - 1)/2;
                
            if (first % 2 == 0) {
                if (tempS < first/2) {
                    dfs2(first + 1, second, count + 1);
                    return;
                }
                if (((tempS - first/2) + 3) < second - first) {
                    dfs2(first/2, second, count + 1);
                    return;
                } else {
                    dfs2(first + 1, second, count + 1);
                    return;
                }
            } else {
                dfs2(first + 1, second, count + 1);
                return;
            }
        }
    }
}

void dfs(ll first, ll second, int count) {
    if (first == second) {
        rslt = count;
        return;
    }
    
    if (first > second) {
        if (first % 2 == 0) {
            dfs(first/2, second, count + 1);
            return;
        } else {
            dfs(first + 1, second, count + 1);
            return;
        }
    }
    if (first < second) {
        dfs2(first, second, count);
        int temp1 = rslt;
        int index = 1;
        int temp3 = 0;
        while (second > 1) {
            if (second % 2 == 0) {
                second = second / 2;
                dfs2(first, second, count);
                int temp2 = rslt + index;
                if (temp2 < temp1) {
                    temp3 = temp2;
                    temp1 = temp2;
                }
                index++;
            } else {
                second = (second - 1) / 2;
                dfs2(first, second, count);
                int temp2 = rslt + index + 1;
                if (temp2 < temp1) {
                    temp3 = temp2;
                    temp1 = temp2;
                }
                index += 2;
            }
        }
        rslt = temp3;
    }
}

int main() {
    freopen("soulmates.in", "r", stdin);
    freopen("soulmates.out", "w", stdout);
    vector<cows> list;
    vector<ll> test;
    int N;
    cin >> N;
    list.resize(N);
    test.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> list[i].first >> list[i].second;
        int distance = abs(list[i].second - list[i].first);
        dfs(list[i].first, list[i].second, 0);
        test[i] = rslt;
    }

    for (int i = 0; i < N; i++) {
        cout << test[i] << "\n";
    }
}