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
    int n, m, l, r, mid;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    l = 0;
    r = n;
    while (l < r) {
        mid = l + (r - l) / 2 + 1;
        int pos = 0;
        for (int i = 0; i < m; ++i) {
            if (pos < mid && s[pos] == t[i]) {
                ++pos;
            }
        }
        if (pos < mid) {
            r = mid - 1;
        }
        else {
            l = mid;
        }
    }
    cout << l << "\n";
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