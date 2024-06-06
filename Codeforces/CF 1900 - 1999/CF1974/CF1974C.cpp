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
    int n;
    ll ans = 0;
    cin >> n;
    map<array<int, 3>, int> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i < n; ++i) {
        int x = a[i - 2], y = a[i - 1], z = a[i];
        ans += m[{-1, y, z}] + m[{x, -1, z}] + m[{x, y, -1}] - m[{x, y, z}] * 3;
        ++m[{x, y, z}];
        ++m[{-1, y, z}];
        ++m[{x, -1, z}];
        ++m[{x, y, -1}];
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