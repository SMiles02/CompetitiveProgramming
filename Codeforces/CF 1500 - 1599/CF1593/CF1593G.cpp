#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), q;
    vector<int> p(n + 2);
    for (int i = 0; i < n; ++i) {
        p[i + 2] = p[i] + (s[i] == '(' || s[i] == ')');
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << abs((p[r + 1] - p[l]) - (p[r] - p[l - 1])) << "\n";
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