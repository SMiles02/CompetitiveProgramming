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
    string s, d = "", l = "", ds, ls;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if ('a' <= s[i] && s[i] <= 'z') {
            l += s[i];
        }
        else if (i > 0 && 'a' <= s[i - 1] && s[i - 1] <= 'z') {
            cout << "NO\n";
            return;
        }
        else {
            d += s[i];
        }
    }
    ds = d;
    sort(ds.begin(), ds.end());
    ls = l;
    sort(ls.begin(), ls.end());
    if (d == ds && l == ls) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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