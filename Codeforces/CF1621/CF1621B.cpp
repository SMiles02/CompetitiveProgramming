#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, mn = 1e9, mx = -1e9, l, r, c;
    cin >> n;
    map<int, int> m;
    map<array<int, 2>, int> mp;
    while (n--) {
        cin >> l >> r >> c;
        if (m[l] == 0)
            m[l] = c;
        else
            m[l] = min(m[l], c);
        if (m[r] == 0)
            m[r] = c;
        else
            m[r] = min(m[r], c);
        if (mp[{l, r}] == 0)
            mp[{l, r}] = c;
        else
            mp[{l, r}] = min(mp[{l, r}], c);
        mn = min(mn, l);
        mx = max(mx, r);
        if (mp[{mn, mx}])
            cout << min(mp[{mn, mx}], m[mn] + m[mx]) << "\n";
        else
            cout << m[mn] + m[mx] << "\n";
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}