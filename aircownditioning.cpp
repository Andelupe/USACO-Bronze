#include <bits/stdc++.h>

using namespace std;


int findL() {
    // if (i == lN - i) {
    //         rslt += abs(s[i].diff);
    //         break;
    //     } else if (lN - i < i) break;
}
struct stall {
    int current, want, diff;
};

int N;
int main(){
    cin >> N;
    vector<stall> s;
    vector<int> pS;
    s.resize(N);
    pS.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i].want;
    }
    for (int i = 0; i < N; i++) {
        cin >> s[i].current;
        s[i].diff = s[i].want - s[i].current;
        if (i != 0) pS[i] = pS[i - 1] + s[i].diff;
        else pS[i] = s[i].diff;
    }
    
    int currF, currL, rslt = 0, change = 0;
    bool changeF = true, changeL = true;
    int lN = N - 1;
    for (int i = 0; i < N; i++) {
        s[i].diff += change;
        if (changeF) {
            if (s[i].diff == 0) continue;
            else currF = s[i].diff;
            changeF = false;
        }
        currL = findL() + change;

        s[lN - i].diff += change;
        

        
        if (changeL) {
            if (s[lN - i].diff == 0) continue;
            else currL = s[lN - i].diff;
            changeL = false;
        }
        if (currF == currL) {
            rslt += abs(currF);
            change += currF;
            changeF = true; changeL = true;
        } else if (currF < currL) {
            rslt += abs(currF);
            change += currF;
            changeF = true; changeL = false;
        } else {
            rslt += abs(currL);
            change += currL;
            changeF = false; changeL = true;
        }
    }

    cout << rslt << "\n";
}