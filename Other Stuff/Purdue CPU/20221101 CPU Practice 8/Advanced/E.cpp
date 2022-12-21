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

const int N = 1e4 + 2;
int c[N], d[N];
vector<int> e[N], ans, sm, df;
bitset<N> dn;

void dfs(int cur, int col) {
    d[cur] = col;
    dn[cur] = 1;
    if (c[cur]) {
        if (c[cur] == d[cur])
            sm.push_back(cur);
        else
            df.push_back(cur);
    }
    for (int i : e[cur])
        if (!dn[i])
            dfs(i, 3 - col);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        if (!dn[i]) {
            sm.clear();
            df.clear();
            dfs(i, 1);
            if (sm.size() > df.size())
                swap(sm, df);
            for (int j : sm)
                ans.push_back(j);
        }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    return 0;
}