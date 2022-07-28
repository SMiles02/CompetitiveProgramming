#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
int a[N], dp[N], cnt[N];
bitset<N> can_delete[N];

void solve() {
    int n, j, ans = 0, cur, bd, mx;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cnt[j] = 0;
        mx = 0;
        for (int j = i; j <= n; ++j) {
            mx = max(mx, ++cnt[a[j]]);
            if ((j - i + 1) % 2 == 0 && mx <= (j - i + 1) / 2)
                can_delete[i][j] = 1;
            else
                can_delete[i][j] = 0;
       }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = -1e9;
        if (can_delete[1][i - 1])
            dp[i] = 1;
        for (int j = 1; j < i; ++j)
            if (a[j] == a[i] && can_delete[j + 1][i - 1])
                dp[i] = max(dp[i], dp[j] + 1);
        if (can_delete[i + 1][n])
            ans = max(ans, dp[i]);
    }
    cout << max(ans, dp[n]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i; ++j)
            can_delete[i][j] = 1;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}