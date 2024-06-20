#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 2>> b;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            b.push_back({s[i] - 'a', i});
        }
    }
    if (b.empty()) {
        cout << n - 1 << "\n";
        return;
    }
    long long ans = 1LL * (b[0][1] + 1) * (n - b.back()[1]);
    for (int i = 1; i < b.size(); ++i) {
        if (b.size() % i != 0) {
            continue;
        }
        int min_mid = 1e9;
        bool ok = true;
        for (int j = 0; j < b.size(); ++j) {
            if (j >= i) {
                ok &= b[j][0] == b[j - i][0];
                if (j % i != 0) {
                    ok &= b[j][1] - b[j - 1][1] == b[j - i][1] - b[j - i - 1][1];
                }
            }
            if (j % i == 0 && j > 0) {
                min_mid = min(min_mid, b[j][1] - b[j - 1][1] - 1);
            }
        }
        if (ok) {
            for (int j = 0; j <= min(b[0][1], min_mid); ++j) {
                ans += min(n - b.back()[1] - 1, min_mid - j) + 1;
            }
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