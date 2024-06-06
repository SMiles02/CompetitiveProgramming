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
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            cnt += s[i][j] != '.';
        }
        if (cnt & 1) {
            cout << "-1\n";
            return;
        }
    }
    for (int j = 0; j < m; ++j) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += s[i][j] != '.';
        }
        if (cnt & 1) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> cnt(m);
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'L') {
                if (cnt[j]++ & 1) {
                    s[i][j] = 'W';
                    s[i][j + 1] = 'B';
                }
                else {
                    s[i][j] = 'B';
                    s[i][j + 1] = 'W';
                }
            }
            if (s[i][j] == 'U') {
                if (cur++ & 1) {
                    s[i][j] = 'W';
                    s[i + 1][j] = 'B';
                }
                else {
                    s[i][j] = 'B';
                    s[i + 1][j] = 'W';
                }
            }
        }
        cout << s[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}