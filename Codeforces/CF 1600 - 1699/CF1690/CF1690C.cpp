#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int s[n + 1], f[n + 1];
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        cout << f[i] - max(f[i - 1], s[i]) << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}