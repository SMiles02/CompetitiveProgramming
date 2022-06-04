#include <bits/stdc++.h>
using namespace std;
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, t, x, y, c, d = -1;
    long long s = 0;
    cin >> n >> q;
    array<int, 2> a[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0];
        a[i][1] = 0;
        s += a[i][0];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            if (a[x][1] < d) {
                a[x][0] = c;
                a[x][1] = d;
            }
            s += y - a[x][0];
            a[x][0] = y;
        }
        else {
            cin >> x;
            s = 1LL * x * n;
            c = x;
            d = i;
        }
        cout << s << "\n";
    }
    return 0;
}