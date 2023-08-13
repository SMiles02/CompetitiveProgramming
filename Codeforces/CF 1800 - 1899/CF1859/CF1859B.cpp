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
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector<int> c(m);
        for (auto &j : c) {
            cin >> j;
        }
        sort(c.begin(), c.end());
        a[i] = c[0];
        b[i] = c[1];
    }
    sort(a, a + n);
    sort(b, b + n);
    ll ans = a[0];
    for (int i = 1; i < n; ++i) {
        ans += b[i];
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