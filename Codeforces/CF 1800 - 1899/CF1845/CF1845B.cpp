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
    int ans = 1, a, b, c, d, e, f;
    cin >> a >> b;
    cin >> c >> d;
    cin >> e >> f;
    if (c > a && e > a)
        ans += min(c, e) - a;
    if (c < a && e < a)
        ans += a - max(c, e);
    if (d > b && f > b)
        ans += min(d, f) - b;
    if (d < b && f < b)
        ans += b - max(d, f);
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