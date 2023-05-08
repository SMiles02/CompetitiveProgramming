#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 5005;
int f[N];

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

int choose[N][N], a[N];
array<int, 2> dp[N];

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        cout << "1\n";
        return;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int cnt = 0;
        dp[i] = {0, 0};
        for (int j = i; j > 0; --j)
            if (a[i] == a[j]) {
                ++cnt;
                if (cnt >= k) {
                    if (dp[j - 1][0] + 1 > dp[i][0])
                        dp[i] = {dp[j - 1][0] + 1, mul(dp[j - 1][1], choose[cnt - 2][k - 2])};
                    else if (dp[j - 1][0] + 1 == dp[i][0])
                        dp[i][1] = add(dp[i][1], mul(dp[j - 1][1], choose[cnt - 2][k - 2]));
                }
            }
        if (dp[i][0] < dp[i - 1][0])
            dp[i] = dp[i - 1];
        else if (dp[i][0] == dp[i - 1][0])
            dp[i][1] = add(dp[i][1], dp[i - 1][1]);
    }
    cout << dp[n][1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    dp[0] = {0, 1};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                choose[i][j] = 1;
            else
                choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
        }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}