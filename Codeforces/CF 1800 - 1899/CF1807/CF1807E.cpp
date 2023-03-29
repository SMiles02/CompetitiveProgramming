#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, m, k;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    l = 1;
    r = n;
    while (l < r) {
        m = l + (r - l) / 2;
        cout << "? " << m - l + 1;
        for (int i = l; i <= m; ++i)
            cout << " " << i;
        cout << endl;
        cin >> k;
        if (k == p[m] - p[l - 1])
            l = m + 1;
        else
            r = m;
    }
    cout << "! " << l << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}