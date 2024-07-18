#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' && t[i] == '1') {
            cout << "NO\n";
            return;
        }
        if (s[i] == '1') {
            cout << "YES\n";
            return;
        }
    }
    cout << "YES\n";
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