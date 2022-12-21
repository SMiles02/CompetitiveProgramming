#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, x;
    ll p = 0, ans = 0;
    cin >> n >> m >> k;
    vector<ll> mx(m, -1e18);
    mx[0] = - k;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        p += x;
        for (int j = 0; j < m; ++j)
            ans = max(ans, p + mx[j]);
        mx[i % m] = max(mx[i % m], -p) - k;
    }
    cout << ans;
    return 0;
}