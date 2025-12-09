#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 501;
int f[N], dp[N][N], choose[N][N];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a, binpow(b, MOD - 2)); }

int sub(int a, int b) { return add(a, MOD - b); }

int C(int n, int k) { return dv(f[n], mul(f[k], f[n - k])); }

void calc_factorials() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
            choose[i][j] = C(i, j);
    for (int i = 1; i < n; ++i)
        if (s[i] == s[i - 1])
            dp[i - 1][i] = 1;
    for (int i = n - 4; i >= 0; --i)
        for (int j = i + 3; j < n; j += 2) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            for (int k = i + 1; k < j; k += 2)
                dp[i][j] = add(dp[i][j], mul(mul(dp[i][k], dp[k + 1][j]), choose[(j - i + 1) / 2][(k - i + 1) / 2]));
        }
    for (int k = 1; k < n; k += 2) {
        for (int i = 0; i + k < n; ++i)
            cout << dp[i][i + k] << " ";
        cout << "\n";
    }
    cout << dp[0][n - 1];
    return 0;
}