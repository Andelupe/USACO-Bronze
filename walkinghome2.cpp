#include <bits/stdc++.h>

using namespace std;

int T, N, K;

int main()
{
    int rslt;
    cin >> T;
    vector<int> test(T, 0);

    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
        vector<string> list(N, "");
        for (int j = 0; j < N; j++)
        {
            cin >> list[j];
        }
        if (K == 1)
        {
            rslt = 0;
            bool noAddtop = false;
            bool noAddbot = false;
            for (int j = 0; j < N; j++)
            {
                if (list[N - 1][j] == 'H')
                    noAddtop = true;
                if (list[j][0] == 'H')
                    noAddtop = true;
            }
            for (int j = 0; j < N; j++)
            {
                if (list[0][j] == 'H')
                    noAddbot = true;
                if (list[j][N - 1] == 'H')
                    noAddbot = true;
            }
            if (!noAddtop)
                rslt++;
            if (!noAddbot)
                rslt++;
            test[i] = rslt;
        }
        if (K == 2)
        {
            rslt = 0;
            for (int j = 1; j < N; j++)
            { // go right first
                if (list[0][j] == 'H')
                    break;
                for (int k = 0; k < N; k++)
                {
                    if (list[k][j] == 'H')
                        break;
                    if (j == N - 1 && k == N - 1)
                        rslt++;
                    else if (k == N - 1)
                    {
                        for (int l = j + 1; l < N; l++)
                        {
                            if (list[k][l] == 'H')
                                break;
                            if (l == N - 1 && k == N - 1)
                                rslt++;
                        }
                    }
                }
            }

            for (int j = 1; j < N; j++)
            { // go down first
                if (list[j][0] == 'H')
                    break;
                for (int k = 0; k < N; k++)
                {
                    if (list[j][k] == 'H')
                        break;
                    if (j == N - 1 && k == N - 1)
                        rslt++;
                    else if (k == N - 1)
                    {
                        for (int l = j + 1; l < N; l++)
                        {
                            if (list[l][k] == 'H')
                                break;
                            if (l == N - 1 && k == N - 1)
                                rslt++;
                        }
                    }
                }
            }

            test[i] = rslt;
        }
        if (K == 3)
        {
            rslt = 0;
            for (int j = 1; j < N; j++)
            { // j = right
                if (list[0][j] == 'H')
                    break;
                for (int k = 1; k < N; k++)
                { // k = down
                    if (list[k][j] == 'H')
                        break;
                    if (j == N - 1 && k == N - 1)
                        rslt++;
                    for (int l = j + 1; l < N; l++)
                    { // l = right
                        if (list[k][l] == 'H')
                            break;
                        if (l == N - 1 && k == N - 1)
                            rslt++;
                        else if (l == N - 1)
                        {
                            for (int h = k + 1; h < N; h++)
                            { // h = down
                                if (list[h][l] == 'H')
                                    break;
                                if (h == N - 1 && l == N - 1)
                                    rslt++;
                            }
                        }
                    }
                }
            }
            for (int j = 1; j < N; j++)
            { // j = down
                if (list[j][0] == 'H')
                    break;
                for (int k = 1; k < N; k++)
                { // k = right
                    if (list[j][k] == 'H')
                        break;
                    if (j == N - 1 && k == N - 1)
                        rslt++;
                    for (int l = j + 1; l < N; l++)
                    { // l = down;
                        if (list[l][k] == 'H')
                            break;
                        if (l == N - 1 && k == N - 1)
                            rslt++;
                        else if (l == N - 1)
                        {
                            for (int h = k + 1; h < N; h++)
                            { // h = down
                                if (list[l][h] == 'H')
                                    break;
                                if (h == N - 1 && l == N - 1)
                                    rslt++;
                            }
                        }
                    }
                }
            }

            test[i] = rslt;
        }
    }
    for (int i = 0; i < T; i++)
    {
        cout << test[i] << "\n";
    }
}