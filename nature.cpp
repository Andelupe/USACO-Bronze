#include <bits\stdc++.h>

#define ll long long
#define vi vector<ll>
using namespace std;

ll Q, N, X, A, Y, B, K, lcm;
vi ticketPrice;

int gcd (int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool check(ll mid)
{
    int s1 = mid/lcm;
    int s2 = mid/A;
    int s3 = mid/B - s1 + s2;
    return ticketPrice[s1] * (X+Y) + (ticketPrice[s2] - ticketPrice[s1]) * X + (ticketPrice[s3] - ticketPrice[s2]) * Y >= K;
}

int main()
{
    cin >> Q;
    while (Q--)
    {
        cin >> N;
        ticketPrice.resize(N+1, 0);
        // for (int i = 1; i <= N; i++) cin >> ticketPrice[i]; ticketPrice[i] /= 100;
        for (int i = 1; i <= N; i++) ticketPrice[i] += ticketPrice[i - 1];
        sort(ticketPrice.begin(), ticketPrice.end(), greater<int>());
        cin >> X >> A >> Y >> B >> K;

        if (!check(N)) cout << -1 << "\n"; continue;
        ll lo = 0, hi = N;
        while (lo + 1 < hi)
        {
            ll mid = (lo + hi) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid;
        }

        cout << lo << endl;
    }
}