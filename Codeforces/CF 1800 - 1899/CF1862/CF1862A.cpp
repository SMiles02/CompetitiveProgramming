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

string vika = "vika";

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> b(m, vector<bool>(26));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            b[j][s[j] - 'a'] = true;
        }
    }
    for (int a = 0; a < m; ++a) {
        if (!b[a]['a' - 'a']) {
            continue;
        }
        for (int k = 0; k < a; ++k) {
            if (!b[k]['k' - 'a']) {
                continue;
            }
            for (int i = 0; i < k; ++i) {
                if (!b[i]['i' - 'a']) {
                    continue;
                }
                for (int v = 0; v < i; ++v) {
                    if (!b[v]['v' - 'a']) {
                        continue;
                    }
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}