#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0, k, x;
    cin >> n >> k;
    vector<int> cnt(31);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        for (int j = 0; j < 31; ++j)
            if (x & (1 << j))
                ++cnt[j];
    }
    for (int i = 30; i >= 0; --i)
        if (cnt[i] + k >= n) {
            k -= n - cnt[i];
            ans += (1 << i);
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