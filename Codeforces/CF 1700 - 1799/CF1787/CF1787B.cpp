#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0, cur;
    cin >> n;
    vector<array<int, 2>> pf;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            pf.push_back({i, 0});
            while (n % i == 0) {
                n /= i;
                ++pf.back()[1];
            }
        }
    if (n > 1)
        pf.push_back({n, 1});
    for (int i = 0; i < 32; ++i) {
        cur = 1;
        for (auto &j : pf)
            if (j[1] > 0) {
                --j[1];
                cur *= j[0];
            }
        if (cur > 1)
            ans += cur;
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