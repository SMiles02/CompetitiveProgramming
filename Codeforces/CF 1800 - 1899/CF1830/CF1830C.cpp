#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353, N = 6e5 + 1;
int f[N], count_seq[N];

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

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int B = 5;

array<int, B> add(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i) {
        a[i] += b[i];
        if (a[i] >= MOD)
            a[i] -= MOD;
    }
    return a;
}
 
array<int, B> sub(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i) {
        a[i] -= b[i];
        if (a[i] < 0)
            a[i] += MOD;
    }
    return a;
}

array<int, B> mul(array<int, B> a, array<int, B> b) {
    for (int i = 0; i < B; ++i)
        a[i] = (1LL * a[i] * b[i]) % MOD;
    return a;
}

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<array<int, B>> x(n + 1), y(n + 1);
    map<array<int, B>, int> cnt;
    array<int, B> base, cur_hash;
    for (int i = 0; i < B; ++i)
        base[i] = get_rand(n + 1, 1e7);
    cur_hash = base;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        x[l] = add(x[l], cur_hash);
        y[r] = add(y[r], cur_hash);
        cur_hash = mul(cur_hash, base);
    }
    for (int i = 0; i < B; ++i)
        cur_hash[i] = 0;
    ans = 1;
    for (int i = 1; i <= n; ++i) {
        ++cnt[cur_hash = add(cur_hash, x[i])];
        cur_hash = sub(cur_hash, y[i]);
    }
    for (auto i : cnt)
        ans = mul(ans, count_seq[i.second]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    count_seq[0] = 1;
    for (int i = 2; i < N; i += 2)
        count_seq[i] = dv(C(i, i / 2), i / 2 + 1);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}