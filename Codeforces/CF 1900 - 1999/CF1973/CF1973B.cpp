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
    int n, ans = 1;
    cin >> n;
    vector<vector<int>> v(20, {0});
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        for (int j = 0; j < 20; ++j) {
            if (x & (1 << j)) {
                v[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < 20; ++i) {
        if (v[i].size() == 1) {
            continue;
        }
        v[i].push_back(n + 1);
        for (int j = 1; j < v[i].size(); ++j) {
            ans = max(ans, v[i][j] - v[i][j - 1]);
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