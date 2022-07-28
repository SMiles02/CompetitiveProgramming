#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k;
    ll ans = 0;
    int a[n];
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i] / k;
        s.insert(a[i] % k);
    }
    while (!s.empty()) {
        x = *(--s.end());
        s.erase(--s.end());
        if (s.lower_bound(k - x) != s.end()) {
            ++ans;
            s.erase(s.lower_bound(k - x));
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