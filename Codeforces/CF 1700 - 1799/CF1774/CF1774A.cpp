#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n;
    string s;
    cin >> s;
    x = s[0] - '0';
    for (int i = 1; i < n; ++i) {
        if (x > 0) {
            cout << "-";
            x -= s[i] - '0';
        }
        else {
            cout << "+";
            x += s[i] - '0';
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}