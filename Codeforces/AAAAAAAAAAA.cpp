#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 1e5 + 1;
vector<int> e[N];
int d[N];

void dfs(int c, int p, int x) {
    ++d[x];
    for (int i : e[c])
        if (i != p)
            dfs(i, c, x + 1);
}

void solve() {
    int n, q, x, y, ans = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        d[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0, 1);
    for (int i = 0; i < q; ++i)
        cin >> x;
    for (int i = 1; i <= n && d[i] <= q; ++i) {
        q -= d[i];
        ans += d[i];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}