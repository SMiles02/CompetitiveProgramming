#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n), v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    v.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            v.push_back(a[i] - a[i - 1]);
        }
    }
    m = v.size();
    vector<bool> dp(m, true);
    for (int i = m - 2; i >= 0; --i) {
        if (dp[i + 1] == 1 && v[i] == 1) {
            dp[i] = 0;
        }
    }
    if (dp[0]) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
    }
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