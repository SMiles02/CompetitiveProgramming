#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    map<array<char, 2>, int> m;
    for (int i = 0; i < n; ++i)
        ++m[{min(s[i], t[n - i - 1]), max(s[i], t[n - i - 1])}];
    bool odd = n & 1;
    for (auto i : m)
        if (i.second & 1) {
            if (i.first[0] != i.first[1] || !odd) {
                cout << "NO\n";
                return;
            }
            odd = false;
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