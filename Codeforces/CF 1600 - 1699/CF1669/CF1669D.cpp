#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, b = 0, r = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B')
            ++b;
        else if (s[i] == 'R')
            ++r;
        if (s[i] == 'W' || i == n - 1) {
            if (max(r, b) > 0 && min(r, b) == 0) {
                cout << "NO\n";
                return;
            }
            r = 0;
            b = 0;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}