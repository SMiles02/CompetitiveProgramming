#include <bits/stdc++.h>
#define ll long long
using namespace std;

double pi = 3.14159265358979;

void solve() {
    ll r, a, b, s = 0;
    cin >> r >> a >> b;
    for (int i = 0; r > 0; ++i) {
        s += r * r;
        if (i & 1) r /= b;
        else r *= a;
    }
    cout << fixed << setprecision(9) << pi * s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}