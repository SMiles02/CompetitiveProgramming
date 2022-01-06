#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b, c, d, x = 1, y = 1;
    cin >> n >> m >> a >> b >> c >> d;
    for (int i = 0; i < 200; ++i) {
        if (a == c || b == d) {
            cout << i << "\n";
            return;
        }
        if (!(1 <= a + x && a + x <= n))
            x *= -1;
        if (!(1 <= b + y && b + y <= m))
            y *= -1;
        a += x;
        b += y;
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}