#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans, c, d, m;

void rec(int a, int b, int i, int j) {
    if (a == c && b == d) {
        ans = min(ans, i);
        return;
    }
    if (i >= 9) {
        return;
    }
    if (j != 1) {
        rec(b, b, i + 2, 1);
        rec(a & b, b, i + 1, 1);
        rec(a | b, b, i + 1, 1);
    }
    if (j != 2) {
        rec(a, a ^ b, i + 1, 2);
    }
    if (j != 3) {
        rec(a, b ^ m, i + 1, 3);
    }
}

void solve() {
    int a, b;
    cin >> a >> b >> c >> d >> m;
    ans = 100;
    rec(a, b, 0, 0);
    if (ans == 100) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}