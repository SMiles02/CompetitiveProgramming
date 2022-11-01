#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long ans = 0;
    cin >> n;
    string s(n, '1'), t;
    cin >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n && t[j - 1] == '0'; j += i)
            if (s[j - 1] == '1') {
                ans += i;
                s[j - 1] = '0';
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