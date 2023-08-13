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
    int n, d, h, l;
    cin >> n >> d >> h;
    int y[n + 1];
    double ans = 1LL * d * h * n;
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
    }
    y[n] = 2e9;
    for (int i = n - 1; i >= 0; --i) {
        if (y[i] + h > y[i + 1]) {
            // cerr << "Sub: " << ((double)(y[i + 1] - y[i]) / h) * d << " " << (y[i + 1] - y[i]) << "\n";
            ans -= ((double)(h - y[i + 1] + y[i]) / h) * (h - y[i + 1] + y[i]) * d;
        }
    }
    cout << fixed << setprecision(20) << ans / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}