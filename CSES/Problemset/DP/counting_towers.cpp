#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e6 + 1;
int dp[N][2];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i][0] = add(add(dp[i - 1][0], dp[i - 1][0]), dp[i - 1][1]);
        dp[i][1] = add(dp[i - 1][0], mul(dp[i - 1][1], 4));
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << add(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}