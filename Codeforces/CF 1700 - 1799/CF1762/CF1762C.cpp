#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n, ans = 1, cur = 1;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            cur = (cur * 2) % MOD;
        else
            cur = 1;
        ans = (ans + cur) % MOD;
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