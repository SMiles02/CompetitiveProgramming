#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, a, b, c, d, e, f, x, y, p, q, s, t;
    cin >> n;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> x >> y;
    p = a ^ c ^ e;
    q = b ^ d ^ f;
    s = (a + c + e - p) / 2;
    t = (b + d + f - q) / 2;
    if ((s == 1 || s == n) && (t == 1 || t == n)) {
        if (x == s || y == t)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else if (x % 2 == p % 2 && y % 2 == q % 2)
        cout << "NO\n";
    else
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