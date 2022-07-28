#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, x = 0, y = 0, t;
    cin >> n >> m >> k;
    int p[2];
    p[0] = p[1] = 0;
    string s[2], ans = "";
    cin >> s[0];
    cin >> s[1];
    sort(s[0].begin(), s[0].end());
    sort(s[1].begin(), s[1].end());
    while (p[0] < n && p[1] < m) {
        if (s[0][p[0]] < s[1][p[1]])
            t = 0;
        else
            t = 1;
        if (t == x) {
            if (y == k) {
                x = 1 - t;
                y = 0;
            }
        }
        else {
            x = t;
            y = 0;
        }
        ++y;
        ans += s[x][p[x]++];
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