#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int M = 1e6 + 1;
const ll INF = -1e18;
vector<int> f[M];

void solve() {
    int n, m, k;
    ll s = 0, ans = INF;
    cin >> n >> m >> k;
    vector<vector<int>> v(m + 1);
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
        for (int j : f[a[i]])
            v[j].push_back(a[i]);
    }
    for (int i = 1; i <= m; ++i)
        if (v[i].size() > k) {
            sort(v[i].begin(), v[i].end());
            while (v[i].size() > k + 1)
                v[i].pop_back();
            ll cur_sum = 0;
            for (int j : v[i])
                cur_sum += j;
            ans = max(ans, s - cur_sum + i);
        }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i < M; ++i)
        for (int j = i; j < M; j += i)
            f[j].push_back(i);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}