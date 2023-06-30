#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 0, cur = 0, cnt = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        if (i % k == 0) {
            ++ans;
            v[i] = 1;
        }
    for (int i = n - 1; i >= 0; --i) {
        ++cur;
        cnt += v[i];
        if (cnt * k < cur) {
            ++cnt;
            ++ans;
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