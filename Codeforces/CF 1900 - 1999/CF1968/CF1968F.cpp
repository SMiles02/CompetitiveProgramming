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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), p(n + 1);
    map<int, set<int, greater<int>>> s;
    s[0].insert(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
        s[p[i]].insert(i);
        s[p[i]].insert(0);
        // cerr << i << " " << p[i] << "\n";
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        // cout << p[r] << "\n";
        // cout << *s[p[l - 1]].upper_bound(r) << "\n";
        // cout << *s[p[r]].upper_bound(*s[p[l - 1]].upper_bound(r)) << "\n";
        if (p[l - 1] == p[r] || l <= *s[p[r]].lower_bound(*s[p[l - 1]].upper_bound(r))) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
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