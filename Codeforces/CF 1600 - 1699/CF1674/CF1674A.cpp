#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z, c;
    cin >> x >> y;
    if (y % x != 0)
        cout << "0 0\n";
    else
        cout << "1 " << y / x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}