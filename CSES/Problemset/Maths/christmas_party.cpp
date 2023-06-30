#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e6 + 1;
int f[N], dp[N];

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int binpow(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b /= 2;
    }
    return ans;
}

int dv(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = mul(f[i - 1], i);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        dp[i] = sub(dv(f[n], f[n - i]), dp[i - 1]);
    cout << dp[n];
    return 0;
}