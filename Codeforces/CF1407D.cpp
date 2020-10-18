#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int h[n], dp[n];
    vector<int> big, small;
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    for (int i = 0; i < n; ++i)
    {
        dp[i] = i;
        while (! big.empty() && h[big.back()] > h[i])
        {
            dp[i] = min(dp[i], dp[big.back()] + 1);
            big.pop_back();
        }
        if (! big.empty())
        {
            dp[i] = min(dp[i], dp[big.back()] + 1);
            if (h[big.back()] == h[i])
                big.pop_back();
        }
        while (! small.empty() && h[small.back()] < h[i])
        {
            dp[i] = min(dp[i], dp[small.back()] + 1);
            small.pop_back();
        }
        if (! small.empty())
        {
            dp[i] = min(dp[i], dp[small.back()] + 1);
            if (h[small.back()] == h[i])
                small.pop_back();
        }
        big.push_back(i);
        small.push_back(i);
    }
    cout << dp[n-1];
    return 0;
}