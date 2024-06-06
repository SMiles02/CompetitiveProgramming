// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 13;
int a[N];
bitset<N> dp[N], done;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < N; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < N; ++j) {
            done[j] = 0;
        }
        int mex = 0;
        for (int j = i; j <= n; ++j) {
            done[a[j]] = 1;
            while (done[mex]) {
                ++mex;
            }
            for (int k = 0; k < N; ++k) {
                if (dp[i - 1][k]) {
                    dp[j][k ^ mex] = 1;
                }
            }
        }
        dp[i] |= dp[i - 1];
    }
    for (int i = N - 1; i >= 0; --i) {
        if (dp[n][i]) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[0][0] = 1;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}