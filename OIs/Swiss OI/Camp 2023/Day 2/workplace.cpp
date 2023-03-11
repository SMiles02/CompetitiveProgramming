#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    ll a[n], dp[n][2];
    cin >> a[0];
    dp[0][0] = 0;
    dp[0][1] = a[0] * 4;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = a[i] * 4 + max(dp[i - 1][0], dp[i - 1][1] - a[i - 1] - a[i]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}