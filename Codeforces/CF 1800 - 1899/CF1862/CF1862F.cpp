#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
bitset<N> dp;

int calc(int b, int a) {
    return (a + b - 1) / b;
}

void solve() {
    int n, w, f, sm = 0, ans = 1e9;
    cin >> w >> f;
    cin >> n;
    for (int i = 1; i <= n * 10000; ++i) {
        dp[i] = 0;
    }
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        sm += k;
        for (int j = sm; j >= k; --j) {
            if (dp[j - k]) {
                dp[j] = 1;
            }
        }
    }
    for (int i = 0; i <= sm; ++i) {
        if (dp[i]) {
            ans = min(ans, max(calc(w, i), calc(f, sm - i)));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[0] = 1;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}