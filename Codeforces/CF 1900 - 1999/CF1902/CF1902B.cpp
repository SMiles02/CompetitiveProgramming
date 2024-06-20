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
    int n, x, t, l, r, m;
    ll p;
    cin >> n >> p >> x >> t;
    l = 1;
    r = n;
    while (l < r) {
        m = l + (r - l) / 2;
        if (1LL * m * x + 1LL * min(m * 2, (n + 6) / 7) * t < p) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    cout << n - l << "\n";
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