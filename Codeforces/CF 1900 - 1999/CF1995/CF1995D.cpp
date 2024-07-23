#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int get_val(vector<int>& v) {
    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            ans += 1 << i;
        }
    }
    return ans;
}

void solve() {
    int n, c, k, ans = 20;
    string s;
    cin >> n >> c >> k;
    cin >> s;
    vector<int> f(c);
    vector<bool> ok(1 << c, true);
    for (int i = 0; i < k; ++i) {
        ++f[s[i] - 'A'];
    }
    ok[((1 << c) - 1) ^ get_val(f)] = false;
    for (int i = k; i < n; ++i) {
        --f[s[i - k] - 'A'];
        ++f[s[i] - 'A'];
        ok[((1 << c) - 1) ^ get_val(f)] = false;
    }
    ok[((1 << c) - 1) ^ (1 << (s[n - 1] - 'A'))] = false;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < (1 << c); ++j) {
            if (j & (1 << i)) {
                ok[j ^ (1 << i)] = ok[j ^ (1 << i)] & ok[j];
            }
        }
    }
    for (int i = 0; i < (1 << c); ++i) {
        if (ok[i]) {
            ans = min(ans, __builtin_popcount(i));
        }
    }
    cout << ans << "\n";
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