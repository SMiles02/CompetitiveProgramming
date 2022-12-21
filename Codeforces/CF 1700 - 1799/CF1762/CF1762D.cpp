#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n, x = 1, y = 2, g, a, b;
    cin >> n;
    g = query(x, y);
    for (int i = 3; i <= n; ++i) {
        a = query(x, i);
        b = query(y, i);
        if (a == max({a, b, g})) {
            g = a;
            y = i;
        }
        else if (b == max({a, b, g})) {
            g = b;
            x = i;
        }
    }
    cout << "! " << x << " " << y << endl;
    int ans;
    cin >> ans;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}