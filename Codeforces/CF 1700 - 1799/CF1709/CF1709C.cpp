#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), x, y, p = 0;
    x = y = n / 2;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            --x;
        else if (s[i] == ')')
            --y;
        else
            v.push_back(i);
    }
    if (x == 0 || y == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i + 1 < x; ++i)
        s[v[i]] = '(';
    s[v[x - 1]] = ')';
    s[v[x]] = '(';
    for (int i = x + 1; i < x + y; ++i)
        s[v[i]] = ')';
    for (auto i : s) {
        if (i == '(')
            ++p;
        else {
            --p;
            if (p < 0) {
                cout << "YES\n";
                return;
            }
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