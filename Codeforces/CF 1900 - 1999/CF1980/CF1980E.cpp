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

vector<vector<int>> rc(int n, int m) {
    vector<vector<int>> a(n, vector<int>(m)), ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<int> v = a[i];
        sort(v.begin(), v.end());
        ans.push_back(v);
    }
    for (int j = 0; j < m; ++j) {
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            v.push_back(a[i][j] - 1e6);
        }
        sort(v.begin(), v.end());
        ans.push_back(v);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (rc(n, m) == rc(n, m)) {
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