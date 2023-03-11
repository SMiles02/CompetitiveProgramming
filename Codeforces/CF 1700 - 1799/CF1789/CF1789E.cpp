#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
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

const int N = 1e6 + 1, M = 1e7 + 1;
int s[N], p[M], a[M];

void solve() {
    int n, last_x = -1, last_y = -1, ans = 0, cur = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= s[n]; ++i)
        a[i] = 0;
    for (int i = 1; i <= n; ++i)
        a[s[i]] = 1;
    for (int i = 1; i <= s[n]; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i * 2 <= s[n]; ++i) {
        int x = s[n] / i, y = (s[n] + i - 1) / i;
        if (!(x == last_x && y == last_y)) {
            cur = 0;
            if (x == y)
                for (int j = x; j <= s[n]; j += x)
                    cur += a[j];
            else {
                for (int j = 1; j <= x && j * x <= s[n]; ++j)
                    cur += p[min(j * x + j, s[n])] - p[j * x - 1];
                if (1LL * x * (x + 1) < s[n])
                    cur += p[s[n]] - p[x * (x + 1)];
            }
        }
        // cout << i << ": " << cur << "\n";
        ans = add(ans, mul(cur, i));
        last_x = x;
        last_y = y;
    }
    for (int i = s[n] / 2 + 1; i <= s[n]; ++i) {
        // cout << i << ": " << p[s[n]] << "\n";
        ans = add(ans, mul(i, p[s[n]]));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}