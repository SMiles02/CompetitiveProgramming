#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, ans, l, r, x, y = 0;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<bool> endHere(n + 2);
    iota(b.begin(), b.end(), 0);
    iota(c.begin(), c.end(), -1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (m--) {
        cin >> l >> r;
        b[l] = max(b[l], r);
    }
    for (int i = 2; i <= n; ++i)
        b[i] = max(b[i - 1], b[i]);
    map<int, vector<int>> mp;
    vector<array<int, 2>> v;
    for (int i = 1; i <= n; ++i) {
        mp[a[i]].push_back(i);
        k = mp[a[i]].size();
        if (k > 1 && i <= b[mp[a[i]][k - 2]]) {
            l = 0;
            r = k - 2;
            while (l < r) {
                m = l + (r - l) / 2;
                if (i <= b[mp[a[i]][m]])
                    r = m;
                else
                    l = m + 1;
            }
            y = max(y, mp[a[i]][k - 2]);
            c[mp[a[i]][l] + 1] = max(c[mp[a[i]][l] + 1], i);
            endHere[mp[a[i]][l + 1] + 1] = true;
        }
    }
    endHere[n + 1] = true;
    ans = y;
    for (x = 2; !endHere[x]; ++x) {
        y = max(y, c[x]);
        ans = min(ans, y - x + 1);
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