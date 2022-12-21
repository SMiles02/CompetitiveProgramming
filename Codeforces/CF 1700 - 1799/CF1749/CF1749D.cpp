#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 3e5 + 1;
int f[N], dp[N][2];
bitset<N> sieve;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0;
    long long m, cur = 1;
    cin >> n >> m;
    dp[1][0] = m % MOD;
    for (int i = 2; i <= n; ++i) {
        if (!sieve[i]) {
            cur = min(cur * i, m + 1);
            for (int j = i * 2; j <= n; j += i)
                sieve[j] = 1;
        }
        dp[i][0] = mul(dp[i - 1][0], (m / cur) % MOD);
        dp[i][1] = add(mul(dp[i - 1][0], (m - m / cur) % MOD), mul(dp[i - 1][1], m % MOD));
        ans = add(ans, dp[i][1]);
    }
    cout << ans << "\n";
    return 0;
}