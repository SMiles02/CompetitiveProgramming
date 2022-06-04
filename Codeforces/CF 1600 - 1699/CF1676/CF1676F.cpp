#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x, l = -1, r = -1;
    cin >> n >> k;
    map<int, int> m, dp;
    set<int> s;
    while (n--) {
        cin >> x;
        s.insert(x);
        ++m[x];
    }
    for (int i : s)
        if (m[i] >= k) {
            dp[i] = dp[i - 1] + 1;
            if (dp[i] >= r - l + 1) {
                l = i - dp[i] + 1;
                r = i;
            }
        }
    if (l == -1)
        cout << "-1\n";
    else
        cout << l << " " << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}