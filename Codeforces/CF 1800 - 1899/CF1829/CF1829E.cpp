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

const int N = 205;
vector<int> e[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    vector<int> v(n + 1), cnt(n + 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        ++v[x];
        ++v[y];
        e[x].push_back(y);
        e[y].push_back(x);
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        ++cnt[v[i]];
        if (v[i] == 1)
            s.insert(e[i][0]);
    }
    cout << s.size() << " " << cnt[1] / s.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}