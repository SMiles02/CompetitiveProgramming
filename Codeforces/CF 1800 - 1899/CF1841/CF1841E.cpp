#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    vector<vector<int>> v(n + 1);
    vector<long long> cnt(n + 1);
    cnt[n] = n;
    set<array<int, 2>> s;
    s.insert({n - 1, 0});
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for (int i = n; i > 0; --i) {
        for (auto j : v[i]) {
            auto [r, l] = *s.lower_bound({j, 0});
            s.erase(s.lower_bound({j, 0}));
            cnt[r - l + 1] -= i;
            if (l <= j - 1) {
                s.insert({j - 1, l});
                cnt[j - l] += i;
            }
            if (j + 1 <= r) {
                s.insert({r, j + 1});
                cnt[r - j] += i;
            }
        }
    }
    long long ans = 0, m;
    cin >> m;
    for (int i = n; i > 1; --i) {
        long long cur = min(cnt[i], m / i);
        m -= cur * i;
        ans += cur * (i - 1);
        cnt[i - 1] += cnt[i] - cur;
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