#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
 
const int MOD = 1e9 + 7, B = 3;
 
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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> cnt(n + 1);
    vector<array<int, B>> bases(n + 1), a(n + 1), p(n + 1);
    array<int, B> zero;
    set<array<int, B>> ans;
    for (int i = 0; i < B; ++i) {
        bases[0][i] = 1;
        bases[1][i] = get_rand(1e4, 1e6);
        zero[i] = 0;
    }
    a[0] = zero;
    p[0] = zero;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            bases[i] = mul(bases[i - 1], bases[1]);
        }
        if (s[i - 1] == '1') {
            a[i] = bases[i];
            cnt[i] = 1;
        }
        else {
            a[i] = zero;
        }
        a[i] = add(a[i - 1], a[i]);
        cnt[i] += cnt[i - 1];
        p[i] = add(p[i - 1], bases[i]);
        // cerr << a[i][0] << " ";
    }
    // cerr << a[n][0] << "\n";
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        array<int, B> new_hash = add(sub(a[n], a[r]), a[l - 1]);
        int one_cnt = cnt[r] - cnt[l - 1];
        new_hash = add(new_hash, sub(p[r], p[r - one_cnt]));
        ans.insert(new_hash);
    }
    cout << ans.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}