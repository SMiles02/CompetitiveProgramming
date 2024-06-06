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
    int n, k;
    cin >> n >> k;
    ll p[n + 1];
    array<int, 2> a[n + 1];
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0];
        a[i][0] = abs(a[i][0]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + a[i][1];
        if ((p[i] + k - 1) / k > a[i][0]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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