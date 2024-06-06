#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s == "()") {
        cout << "NO\n";
        return;
    }
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        ok &= !(s[i] == '(' && s[i - 1] == ')');
    }
    cout << "YES\n";
    if (ok) {
        for (int i = 0; i < n; ++i) {
            cout << "()";
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            cout << "(";
        }
        for (int i = 0; i < n; ++i) {
            cout << ")";
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