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

const int N = 2e5 * 32;
long long ans;
int max_done, a[N][2], cnt[N];

void query(int i, int p, int x, int y, int b) {
    cnt[i] += y;
    if (p == -1) {
        ans = add(ans, mul(mul(y, y), b + 1));
        return;
    }
    if (a[i][1 - min(x & (1 << p), 1)] != 0) {
        ans = add(ans, mul(cnt[a[i][1 - min(x & (1 << p), 1)]], mul(b * 2 + 3, y)));
    }
    if (a[i][min(x & (1 << p), 1)] == 0) {
        a[i][min(x & (1 << p), 1)] = max_done++;
    }
    query(a[i][min(x & (1 << p), 1)], p - 1, x, y, b + min(x & (1 << p), 1));
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < max_done; ++i) {
        a[i][0] = a[i][1] = cnt[i] = 0;
    }
    max_done = 1;
    ans = 0;
    map<int, int> m;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        ++m[k];
    }
    for (auto [x, y] : m) {
        query(0, 29, x, y, 0);
    }
    cout << dv(ans, mul(n, n)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}