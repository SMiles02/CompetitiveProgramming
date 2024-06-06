#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, m, k, lr, lc;
    ll ans = 0;
    cin >> n >> m >> k;
    vector<array<int, 3>> a(k);
    vector<bool> res(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    lr = n;
    lc = m + 1;
    for (int i = k - 1; i >= 0; --i) {
        if (i == 0 || a[i - 1][0] != a[i][0]) {
            ans += 1LL * (lr - a[i][0]) * (lc - 1);
            res[a[i][2]] = a[i][1] < lc;
            lr = a[i][0];
            lc = min(lc, a[i][1]);
        }
    }
    ans += 1LL * a[0][0] * (lc - 1);
    cout << ans << "\n";
    for (auto i : res) {
        cout << i << " ";
    }
    cout << "\n";
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