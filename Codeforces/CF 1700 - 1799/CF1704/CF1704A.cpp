#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    for (int i = 0; i + 1 < m; ++i)
        if (s[n - i - 1] != t[m - i - 1]) {
            cout << "NO\n";
            return;
        }
    vector<bool> b(2);
    for (int i = 0; i <= n - m; ++i)
        b[s[i] - '0'] = true;
    if (b[t[0] - '0'])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}