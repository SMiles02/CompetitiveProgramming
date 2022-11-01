#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, cnt = 0, mn = 4;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    bool dbl = false;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < m; ++j)
            dbl |= (s[i][j] == '0' && s[i][j - 1] == '0');
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dbl |= (s[i][j] == '0' && s[i - 1][j] == '0');
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cnt += (s[i][j] == '1');
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            mn = min(mn, 0 + (s[i][j] == '1') + (s[i - 1][j] == '1') + (s[i][j - 1] == '1') + (s[i - 1][j - 1] == '1'));
    if (dbl)
        cout << cnt << "\n";
    else
        cout << cnt - mn + 2 << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}