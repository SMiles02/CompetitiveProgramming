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

ll s(int x) {
    return 1LL * x * x;
}

void solve() {
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        int l1 = 1, r1 = n + 1, m1, l2 = 1, r2 = n + 1, m2;
        while (l1 < r1) {
            m1 = l1 + (r1 - l1) / 2;
            if (s(m1) < s(n) - s(i)) {
                l1 = m1 + 1;
            }
            else {
                r1 = m1;
            }
        }
        while (l2 < r2) {
            m2 = l2 + (r2 - l2) / 2 + 1;
            if (s(m2) < s(n + 1) - s(i)) {
                l2 = m2;
            }
            else {
                r2 = m2 - 1;
            }
        }
        ans += max(l2 - l1 + 1, 0);
    }
    cout << ans * 4 << "\n";
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