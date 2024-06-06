#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, m, k, lr, lc;
    ll ans = 0;
    cin >> n >> m >> k;
    vector<array<int, 3>> a(k + 1);
    vector<ll> res(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    a[k] = {0, 1, k};
    sort(a.begin(), a.end());
    lr = n;
    lc = m + 1;
    vector<array<int, 2>> lp = {{n, m + 1}};
    for (int i = k; i >= 0; --i) {
        if (i == 0 || a[i - 1][0] != a[i][0]) {
            ans += 1LL * (lr - a[i][0]) * (lc - 1);
            if (i == 0 || a[i][1] < lc) {
                lc = a[i][1];
                lp.push_back({a[i][0], a[i][1]});
            }
            lr = a[i][0];
        }
    }
    lr = n;
    lc = m + 1;
    for (int i = k; i > 0; --i) {
        if (i == 0 || a[i - 1][0] != a[i][0]) {
            ans += 1LL * (lr - a[i][0]) * (lc - 1);
            // res[a[i][2]] = a[i][1] < lc;
            if (a[i][1] < lc) {
                int l = 0, r = lp.size() - 1, m;
                while (l < r) {
                    m = l + (r - l) / 2;
                    if (lp[m][0] > a[i][0]) {
                        l = m + 1;
                    }
                    else {
                        r = m;
                    }
                }
                
                lc = a[i][1];
            }
            lr = a[i][0];
        }
    }
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