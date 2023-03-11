#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, m, x, y;
    ll ans = 0;
    cin >> n >> m;
    int a[n + 1];
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]] = m + 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        mp[a[x]] -= m - i;
        a[x] = y;
        mp[a[x]] += m - i;
    }
    for (auto i : mp) {
        ans += (1LL * i.second * (i.second - 1)) / 2;
        ans += 1ll * i.second * (m + 1 - i.second);
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