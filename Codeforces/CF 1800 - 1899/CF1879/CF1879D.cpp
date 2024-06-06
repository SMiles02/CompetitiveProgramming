#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = 2e5 + 1;
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), c(30);
    vector<array<array<int, 2>, 2>> cnt(30);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 30; ++j) {
            ++cnt[j][c[j] & 1][0];
            cnt[j][c[j] & 1][1] = add(cnt[j][c[j] & 1][1], i);
            if (a[i] & (1 << j)) {
                ++c[j];
            }
            ans = add(ans, mul(1 << j, add(sub(mul(i, cnt[j][(c[j] + 1) & 1][0]), cnt[j][(c[j] + 1) & 1][1]), cnt[j][(c[j] + 1) & 1][0])));
        }
    }
    cout << ans << "\n";
    return 0;
}