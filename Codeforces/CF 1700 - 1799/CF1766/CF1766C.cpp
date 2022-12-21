#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cur = 2;
    bool ok = true;
    cin >> n;
    string s[2];
    cin >> s[0];
    cin >> s[1];
    for (int i = 0; i < n; ++i) {
        if (cur == 2) {
            if (s[0][i] == 'B' && s[1][i] == 'W')
                cur = 0;
            if (s[0][i] == 'W' && s[1][i] == 'B')
                cur = 1;
        }
        else {
            if (s[cur][i] == 'W')
                ok = false;
            if (s[cur ^ 1][i] == 'B')
                cur ^= 1;
        }
    }
    if (ok)
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