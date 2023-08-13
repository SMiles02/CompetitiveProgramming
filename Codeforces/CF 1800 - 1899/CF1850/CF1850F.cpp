#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k <= n) {
            ++cnt[k];
        }
    }
    for (int i = n; i > 0; --i) {
        for (int j = i * 2; j <= n; j += i) {
            cnt[j] += cnt[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, cnt[i]);
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