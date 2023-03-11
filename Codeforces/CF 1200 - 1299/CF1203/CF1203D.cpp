#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size(), m = t.size(), x = 0, ans = 0;
    vector<int> v(m + 2, -1), w(m + 2, -1);
    v[0] = 0;
    for (int i = 0; i < n; ++i)
        if (x < m && s[i] == t[x])
            v[++x] = i + 1;
    w[m + 1] = n + 1;
    x = m - 1;
    for (int i = n - 1; i >= 0; --i)
        if (x >= 0 && s[i] == t[x])
            w[--x + 2] = i + 1;
    for (int i = 0; i <= m; ++i)
        ans = max(ans, w[i + 1] - v[i] - 1);
    if (v[m] == 0)
        ans = -1;
    cout << ans;
    return 0;
}