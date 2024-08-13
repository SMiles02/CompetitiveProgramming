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
    int n, m, k, w;
    cin >> n >> m >> k;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; ++i) {
        cin >> a[i];
    }
    vector<int> g(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i * m + j] = (min(i, n - k) - max(i - k + 1, 0) + 1) * (min(j, m - k) - max(j - k + 1, 0) + 1);
        }
    }
    sort(a.rbegin(), a.rend());
    sort(g.rbegin(), g.rend());
    long long ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += 1LL * a[i] * g[i];
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