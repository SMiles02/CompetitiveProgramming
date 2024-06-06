#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 130, M = 1e5 + 2, K = 64;
int cnt[N];

int add(int a, int b) {
    assert(a >= 0);
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, long long b) {
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

vector<int> solve_sing(long long x, long long n) {
    vector<int> f(K);
    int cur_level = 1;
    long long l = x, r = x;
    while (l <= n) {
        r = min(r, n);
        f[cur_level] = (r - l + 1) % MOD;
        l *= 2;
        r = r * 2 + 1;
        ++cur_level;
    }
    return f;
}

void solve_sub(long long x, long long n, int f) {
    vector<int> cmb(N), lc = solve_sing(x * 2, n), rc = solve_sing(x * 2 + 1, n);
    cmb[1] = 1;
    for (int i = 1; i < K; ++i) {
        cmb[i + 1] = add(lc[i], rc[i]);
    }
    for (int i = 1; i < K; ++i) {
        for (int j = 1; j < K; ++j) {
            cmb[i + j + 1] = add(cmb[i + j + 1], mul(lc[i], rc[j]));
        }
    }
    for (int i = 1; i < N; ++i) {
        cnt[i] = add(cnt[i], mul(cmb[i], f % MOD));
    }
}

void solve() {
    long long n, l = 1, r = 1;
    int m, ans = 0;
    cin >> n >> m;
    while (l <= n) {
        r = min(r, n);
        long long tmp = n;
        while (tmp > r) {
            tmp /= 2;
        }
        if (l <= tmp - 1) {
            solve_sub(l, n, (tmp - l) % MOD);
        }
        if (tmp + 1 <= r) {
            solve_sub(r, n, (r - tmp) % MOD);
        }
        solve_sub(tmp, n, 1);
        l *= 2;
        r = r * 2 + 1;
    }
    vector<int> cur(m + 1, 1);
    int mul_con = binpow(m, n - 1);
    for (int i = 1; i < N; ++i) {
        int tot_sum = 1, ways = 1;
        for (int j = 1; j <= m; ++j) {
            cur[j] = mul(cur[j], j);
            tot_sum = add(tot_sum, mul(j, sub(cur[j], ways)));
            ways = cur[j];
        }
        ans = add(ans, mul(mul(tot_sum, cnt[i]), mul_con));
        mul_con = dv(mul_con, m);
        cnt[i] = 0;
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