#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000][3];

int solve(int x, bool print) {
    int ans = 0, cur, t, z, y, k, tmp = m;
    if (print)
        cout << x << "\n";
    for (int i = 0; i < n; ++i) {
        t = a[i][0];
        z = a[i][1];
        y = a[i][2];
        k = t * z + y;
        cur = (x / k) * z + min(z, (x % k) / t);
        ans += cur;
        if (print) {
            cur = min(tmp, cur);
            cout << cur << " ";
            tmp -= cur;
        }
    }
    if (print)
        cout << "\n";
    return ans;
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l = 0, r = 3e7, mid;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    while (l < r) {
        mid = l + (r - l) / 2;
        if (solve(mid, 0) < m)
            l = mid + 1;
        else
            r = mid;
    }
    solve(l, 1);
    return 0;
}