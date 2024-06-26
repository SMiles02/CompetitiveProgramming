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
    map<int, int> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v[i].push_back(k);
        for (int j = 0; j < v[i][0]; ++j) {
            cin >> k;
            v[i].push_back(k);
            ++m[k];
        }
    }
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 1; j <= v[i][0]; ++j) {
            ok &= m[v[i][j]] > 1;
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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