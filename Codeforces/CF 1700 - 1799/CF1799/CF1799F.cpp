#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x, y;
    long long ans = 1e18;
    cin >> n >> k >> x >> y;
    vector<int> a(n);
    for (auto &ai : a) {
        cin >> ai;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i <= min(x, y); ++i) {
        if (x + y - i > n) {
            continue;
        }
        long long cur = 0;
        for (int j = 0; j < i; ++j) {
            cur += max((a[j] + 1) / 2 - k, 0);
        }
        for (int j = x + y - i; j < n; ++j) {
            cur += a[j];
        }
        for (int j = i; j < x + y - i; ++j) {
            cur += (a[j] + 1) / 2;
        }
        for (int j = i; j < y; ++j) {
            cur += max(a[j] - k, 0) - (a[j] + 1) / 2;
        }
        for (int j = y - 1; j < x + y - i; ++j) {
            if (j >= y) {
                cur -= max(a[j - y + i] - k, 0) - (a[j - y + i] + 1) / 2;
                cur += max(a[j] - k, 0) - (a[j] + 1) / 2;
            }
            ans = min(ans, cur);
        }
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