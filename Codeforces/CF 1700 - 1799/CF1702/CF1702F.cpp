#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        while (!(k & 1))
            k /= 2;
        ++m[k];
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        while (m[k] == 0 && k > 0)
            k /= 2;
        if (k == 0)
            ok = false;
        else
            --m[k];
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