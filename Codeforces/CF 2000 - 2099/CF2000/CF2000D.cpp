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
    long long ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    string s;
    cin >> s;
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            l.push_back(i + 1);
        }
        else {
            r.push_back(i + 1);
        }
    }
    reverse(r.begin(), r.end());
    for (int i = 0; i < min(l.size(), r.size()); ++i) {
        if (l[i] <= r[i]) {
            ans += p[r[i]] - p[l[i] - 1];
        }
    }
    cout << ans << "\n";
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