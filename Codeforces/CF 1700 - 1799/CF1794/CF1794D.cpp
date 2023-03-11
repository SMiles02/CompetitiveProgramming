#include <bits/stdc++.h>
using namespace std;

const int N = 4050, MXA = 1e6 + 1;
int dp[N][N], cnt[MXA];

const int MOD = 998244353;
int f[N], fi[N];

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
    f[0] = fi[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
        fi[i] = binpow(f[i], MOD - 2);
    }
}

bool is_prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int n, k = 0;
    cin >> n;
    int a[n * 2];
    for (int i = 0; i < n * 2; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a, a + n * 2);
    dp[0][0] = f[n];
    for (int i = 1; i < MXA; ++i)
        if (cnt[i] > 0) {
            ++k;
            if (is_prime(i)) {
                dp[k][0] = mul(dp[k - 1][0], fi[cnt[i]]);
                for (int j = 1; j <= n; ++j)
                    dp[k][j] = add(mul(dp[k - 1][j], fi[cnt[i]]), mul(dp[k - 1][j - 1], fi[cnt[i] - 1]));
            }
            else
                for (int j = 0; j <= n; ++j)
                    dp[k][j] = mul(dp[k - 1][j], fi[cnt[i]]);
        }
    cout << dp[k][n] << "\n";
    return 0;
}