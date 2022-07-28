#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, x, m = 0;
    cin >> n >> s;
    int p[n + 1], f[n + 1];
    p[0] = 0;
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        p[i] = p[i - 1] + x;
        if (x)
            f[p[i]] = i;
        if (p[i] >= s)
            m = max(m, i - f[p[i] - s]);
    }
    if (p[n] < s)
        cout << "-1\n";
    else
        cout << n - m << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}