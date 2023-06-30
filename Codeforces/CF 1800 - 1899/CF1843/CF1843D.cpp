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

const int N = 2e5 + 1;
int sub[N];
vector<int> e[N];

void dfs(int c, int p) {
    sub[c] = 0;
    for (int i : e[c]) {
        if (i != p) {
            dfs(i, c);
            sub[c] += sub[i];
        }
    }
    if (sub[c] == 0) {
        sub[c] = 1;
    }
}

void solve() {
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << 1LL * sub[x] * sub[y] << "\n";
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