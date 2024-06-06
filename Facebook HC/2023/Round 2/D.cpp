#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9 + 7, N = 1e6 + 3;
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

int cnt[N], gp[N];

void solve() {
    int n, k, d, ans = 0;
    cin >> n >> k >> d;
    vector<int> h(n);
    for (int i = 1; i < N; ++i) {
        cnt[i] = 0;
        gp[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        ++cnt[h[i]];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i * 2; j < N; j += i) {
            cnt[i] += cnt[j];
        }
    }
    for (int i = N - 1; i >= 1; --i) {
        if (cnt[i] >= k) {
            gp[i] = C(cnt[i], k);
            for (int j = i * 2; j < N; j += i) {
                gp[i] = sub(gp[i], gp[j]);
            }
            if (d % i == 0) {
                ans = add(ans, gp[i]);
            }
        }
    }
    cout << mul(ans, f[k]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}