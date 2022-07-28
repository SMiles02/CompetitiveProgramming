#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
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

const int N = 205;
int n, a[N][3], cnt;
vector<int> e[N];
bitset<N> dn;

void dfs(int c) {
    ++cnt;
    dn[c] = 1;
    for (int i : e[c])
        if (!dn[i])
            dfs(i);
}

bool ok(int s) {
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (1LL * s * a[i][2] >= abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1])) {
                e[i].push_back(j);
                // cout << i << " " << j << "\n";
            }
    // return 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cnt = 0;
        dn.reset();
        dfs(i);
        ans = max(ans, cnt);
    }
    return (ans == n);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    // ok(2);
    // return 0;
    int l = 0, r = 4e9, m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (ok(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l;
    return 0;
}