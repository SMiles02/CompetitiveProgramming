#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    bool ok = true;
    if (s[0] == 'B' || s.back() == 'A')
        ok = false;
    for (auto i : s) {
        if (i == 'A')
            ++a;
        else {
            ++b;
            if (b > a)
                ok = false;
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