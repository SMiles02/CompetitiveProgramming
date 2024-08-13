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
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        map<int, char> m;
        map<char, int> p;
        for (int i = 0; i < n; ++i) {
            if ((m.count(a[i]) && m[a[i]] != s[i]) || (p.count(s[i]) && p[s[i]] != a[i])) {
                ok = false;
            }
            m[a[i]] = s[i];
            p[s[i]] = a[i];
        }
        if (ok) {
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