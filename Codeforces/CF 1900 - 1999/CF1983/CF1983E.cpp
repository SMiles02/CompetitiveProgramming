#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

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

void solve() {
    int n, k, ans;
    cin >> n >> k;
    vector<int> v(n), sum(2);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum[i < k] = add(sum[i < k], v[i]);
    }
    ans = mul(sum[0], dv((n - k + 1) / 2, n - k));
    ans = add(ans, mul(sum[1], dv((n - k + 2) / 2, n - k + 1)));
    cout << ans << " " << sub(add(sum[0], sum[1]), ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}