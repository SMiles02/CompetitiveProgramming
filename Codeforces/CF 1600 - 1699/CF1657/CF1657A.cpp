#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z, s;
    cin >> x >> y;
    z = x * x + y * y;
    s = sqrt(z);
    if (z == 0)
        cout << "0\n";
    else if (s * s == z)
        cout << "1\n";
    else
        cout << "2\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}