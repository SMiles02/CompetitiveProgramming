#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), p, c = 0;
    cin >> p;
    vector<bool> b(n);
    vector<array<int, 2>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = {s[i] - 'a' + 1, i};
        c += v[i][0];
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n && c > p; ++i) {
        c -= v[i][0];
        b[v[i][1]] = 1;
    }
    for (int i = 0; i < n; ++i)
        if (b[i] == 0)
            cout << s[i];
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