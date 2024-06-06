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
    vector<int> x(n), y(n), c(n), l, a, b;
    vector<array<int, 2>> v;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        v.push_back({x[i], 0});
    }
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        v.push_back({y[i], 1});
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * 2; ++i) {
        if (v[i][1] == 0) {
            a.push_back(v[i][0]);
        }
        else {
            l.push_back(v[i][0] - a.back());
            a.pop_back();
        }
    }
    sort(c.begin(), c.end());
    sort(l.rbegin(), l.rend());
    for (int i = 0; i < n; ++i) {
        ans += 1LL * l[i] * c[i];
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