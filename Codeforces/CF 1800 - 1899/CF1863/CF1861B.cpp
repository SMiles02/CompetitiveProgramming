#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s;
    cin >> t;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == '0' && s[i] == '1' && t[i - 1] == '0' && t[i] == '1') {
            cout << "YES\n";
            return;
        }
    }
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