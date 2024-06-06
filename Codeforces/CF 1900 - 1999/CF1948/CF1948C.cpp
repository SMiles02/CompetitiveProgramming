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

const int N = 8e5 + 8;
bitset<N> dn;
vector<int> e[N];

void dfs(int c) {
    dn[c] = 1;
    for (int i : e[c]) {
        if (!dn[i]) {
            dfs(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0];
    cin >> s[1];
    for (int i = 0; i < n * 4; ++i) {
        e[i].clear();
        dn[i] = 0;
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '<') {
                e[i * n + j + n * 2].push_back(i * n + j - 1);
            }
            else {
                e[i * n + j + n * 2].push_back(i * n + j + 1);
            }
            if (i == 0) {
                e[j].push_back(n + j + n * 2);
            }
            else {
                e[j + n].push_back(j + n * 2);
            }
            if (j != 0) {
                e[i * n + j].push_back(i * n + j - 1 + n * 2);
            }
            if (j != n - 1) {
                e[i * n + j].push_back(i * n + j + 1 + n * 2);
            }
        }
    }
    dfs(0);
    if (dn[n * 2 - 1]) {
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