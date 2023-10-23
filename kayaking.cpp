#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct kayak {
    int diff, index;
    bool taken;
};

bool cmp(kayak a, kayak b) {
    return a.diff > b.diff;
}

int main() {
    vector<int> weight;
    vector<kayak> weightDiff;
    vector<kayak> tempDiff;
    int n;
    cin >> n;
    weight.resize(2 * n);
    weightDiff.resize((2 * n) - 1);
    int rslt = 0;

    for (int i = 0; i < 2 * n; i++) {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());
    for (int i = 1; i < weight.size(); i++) {
        kayak k;
        k.index = i - 1;
        k.diff = weight[i] - weight[i - 1];
        k.taken = false;
        weightDiff[i - 1] = k;
    }
    tempDiff = weightDiff;
    sort(weightDiff.begin(), weightDiff.end(), cmp);
    for (int i = 0; i < weightDiff.size(); i++) {
        if (tempDiff[weightDiff[i].index].taken) continue;
        if (i == 0) {
            tempDiff[weightDiff[i].index].taken = true;
            if (weightDiff[i].index == 0) {  
                continue;
            }
            tempDiff[weightDiff[i].index - 1].taken = true;
            continue;
        }
        
        if (weightDiff[i].index == 0) {
            rslt += weightDiff[i].diff;
            tempDiff[weightDiff[i].index].taken = true;
            continue;
        }
        if (tempDiff[weightDiff[i].index - 1].taken) continue;

        rslt += weightDiff[i].diff;
        tempDiff[i].taken = true;
        tempDiff[weightDiff[i].index - 1].taken = true;
        
    }
    cout << rslt << "\n";
}