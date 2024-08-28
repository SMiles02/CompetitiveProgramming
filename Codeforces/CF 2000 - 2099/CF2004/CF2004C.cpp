#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            ans -= a[i];
        }
        else {
            ans += a[i];
        }
    }
    for (int i = 1; i < n; i += 2) {
        int cur = min(a[i - 1] - a[i], k);
        ans -= cur;
        k -= cur;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}