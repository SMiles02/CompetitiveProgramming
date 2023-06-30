#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    if (p[n] < min(p[1], p[2]))
        cout << p[n] << " " << min(p[1], p[2]) << "\n";
    else if (max(p[1], p[2]) < p[n])
        cout << max(p[1], p[2]) << " " << p[n] << "\n";
    else
        cout << p[1] << " " << p[2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}