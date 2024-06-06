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
    ll tot = 0, ans = 1e18;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        tot += abs(a[i] - b[i]);
    }
    for (int i = 0; i < n; ++i) {
        ans = min({ans, tot + min({abs(a[i] - b[n]), abs(b[i] - b[n]), abs(a[i] - b[n]) + abs(b[n] - b[i]) - abs(a[i] - b[i])}) + 1});
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