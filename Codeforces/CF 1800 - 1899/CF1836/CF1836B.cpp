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
    int n, k, g, m;
    cin >> n >> k >> g;
    ll ans = k * g;
    m = (g + 1) / 2 - 1;
    if (1LL * m * n >= 1LL * k * g) {
        cout << 1LL * k * g << "\n";
        return;
    }
    cout << 1LL * k * g - 1LL * (((1LL * k * g) - (1LL * m * n) + g - 1) / g) * g << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}