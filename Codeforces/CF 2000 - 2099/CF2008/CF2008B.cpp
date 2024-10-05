#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    string s;
    cin >> s;
    m = sqrt(n);
    bool ok = m * m == n;
    for (int i = 0; i < m; ++i) {
        ok &= s[i] == '1' && s[n - i - 1] == '1';
    }
    for (int i = 1; i + 1 < m; ++i) {
        ok &= s[i * m] == '1' && s[(i + 1) * m - 1] == '1';
        for (int j = 1; j + 1 < m; ++j) {
            ok &= s[i * m + j] == '0';
        }
    }
    if (ok) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}