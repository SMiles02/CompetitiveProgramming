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

const int N = 505;
int g[N][N];

void solve() {
    int n, s = 0;
    cin >> n;
    vector<vector<int>> ans;
    for (int i = n; i > 0; --i) {
        vector<int> cur(n + 2);
        iota(cur.begin(), cur.end(), -1);
        cur[0] = 1;
        cur[1] = i;
        ans.push_back(cur);
        cur[0] = 2;
        ans.push_back(cur);
        for (int j = 1; j <= n; ++j) {
            g[i][j] = g[j][i] = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        s += i * (i * i - (i - 1) * (i - 1));
    }
    cout << s << " " << ans.size() << "\n";
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    // cout << "Grid:\n";
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
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