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
    vector<int> a(n), b(n);
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s1 += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        s2 += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << min(s1 + 1LL * n * b[0], s2 + 1LL * n * a[0]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}