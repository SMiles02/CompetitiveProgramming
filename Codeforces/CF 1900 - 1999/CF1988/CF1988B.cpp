#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0, y = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++x;
        }
        else if (i == 0 || s[i] != s[i - 1]) {
            ++y;
        }
    }
    if (x > y) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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