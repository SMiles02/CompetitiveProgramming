#include <bits/stdc++.h>
using namespace std;

array<int, 2> extend(array<int, 2> a, char c) {
    if (c == 'U') {
        ++a[1];
    }
    else if (c == 'D') {
        --a[1];
    }
    else if (c == 'L') {
        --a[0];
    }
    else {
        ++a[0];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int, 2>> v(n + 2), w(n + 2);
    set<array<int, 3>> a, b;
    for (int i = 0; i < n; ++i) {
        v[i + 1] = extend(v[i], s[i]);
        a.insert({v[i + 1][0], v[i + 1][1], i + 1});
    }
    for (int i = n - 1; i >= 0; --i) {
        w[i + 1] = extend(w[i + 2], s[i]);
        b.insert({w[i + 1][0], w[i + 1][1], i + 1});
    }
    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        bool ok = (x == 0 && y == 0) || (x == v[n][0] && y == v[n][1]);
        if (a.upper_bound({x, y, -1}) != a.end()) {
            int i = (*a.upper_bound({x, y, -1}))[2];
            if (i < l && v[i][0] == x && v[i][1] == y) {
                ok = true;
            }
        }
        if (a.upper_bound({x, y, r}) != a.end()) {
            int i = (*a.upper_bound({x, y, r}))[2];
            if (v[i][0] == x && v[i][1] == y) {
                ok = true;
            }
        }
        int tx = x - v[l - 1][0] + w[r + 1][0], ty = y - v[l - 1][1] + w[r + 1][1];
        if (b.upper_bound({tx, ty, l - 1}) != b.end()) {
            int i = (*b.upper_bound({tx, ty, l - 1}))[2];
            if (i <= r && w[i][0] == tx && w[i][1] == ty) {
                ok = true;
            }
        }
        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}