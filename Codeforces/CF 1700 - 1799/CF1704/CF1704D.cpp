#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m;
    long long cur;
    vector<array<long long, 2>> v;
    for (int i = 0; i < n; ++i) {
        cur = 0;
        for (int j = 1; j <= m; ++j) {
            cin >> k;
            cur += 1LL * j * k;
        }
        v.push_back({cur, i});
    }
    sort(v.begin(), v.end());
    cout << v.back()[1] + 1 << " " << v.back()[0] - v[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}