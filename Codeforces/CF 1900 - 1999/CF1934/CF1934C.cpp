#include <bits/stdc++.h>
using namespace std;

int make_query(int x, int y) {
    int ans;
    cout << "? " << x << " " << y << endl;
    cin >> ans;
    return ans;
}

void make_guess(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

void solve() {
    int n, m, a, b, c, x, y;
    cin >> n >> m;
    a = make_query(1, 1);
    b = make_query(n, m);
    c = make_query(1, m);
    x = (a + c - m + 1) / 2 + 1;
    y = a - x + 2;
    if (x < 1 || n < x || y < 1 || m < y || make_query(x, y) != 0) {
        y = m - (b + c - n + 1) / 2;
        x = n - b + m - y;
    }
    make_guess(x, y);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}