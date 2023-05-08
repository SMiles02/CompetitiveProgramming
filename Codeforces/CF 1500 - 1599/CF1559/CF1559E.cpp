#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][2], ans[m + 1];
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    for (int i = m; i >= 1; --i) {
        ans[i] = 1;
        for (int j = 0; j < n; ++j)
            ans[i] = mul(ans[i], (a[j][1] / i) - ((a[j][0] - 1) / i));
        for (int j = i * 2; j <= m; j += i)
            ans[i] = sub(ans[i], ans[j]);
    }
    cout << ans[1];
    return 0;
}