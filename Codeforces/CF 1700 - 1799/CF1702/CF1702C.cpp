#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, x, y;
    cin >> n >> q;
    map<int, int> mn, mx;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (mn[x] == 0)
            mn[x] = i;
        mx[x] = i;
    }
    while (q--) {
        cin >> x >> y;
        if (mx[x] == 0 || mx[y] == 0 || mn[x] > mx[y])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}