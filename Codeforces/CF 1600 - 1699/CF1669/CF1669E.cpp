#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    map<string, int> m;
    map<char, int> f, s;
    string t;
    while (n--) {
        cin >> t;
        ans += f[t[0]] + s[t[1]] - 2 * m[t];
        ++m[t];
        ++f[t[0]];
        ++s[t[1]];
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