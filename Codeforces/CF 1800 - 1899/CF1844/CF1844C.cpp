#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> ans(3);
    ans[2] = -1e9;
    while (n--) {
        int ai;
        cin >> ai;
        ans[2] = max(ans[2], (long long)ai);
        ans[n & 1] += max(ai, 0);
    }
    if (ans[2] <= 0) {
        cout << ans[2] << "\n";
        return;
    }
    cout << max({ans[0], ans[1], ans[2]}) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}