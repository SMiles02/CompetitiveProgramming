#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, z;
    cin >> n;
    x = (n + 5) / 3;
    n -= x;
    if (n & 1) {
        y = (n + 1) / 2;
        z = n / 2;
    }
    else {
        y = n / 2 + 1;
        z = n / 2 - 1;
    }
    cout << y << " " << x << " " << z << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}