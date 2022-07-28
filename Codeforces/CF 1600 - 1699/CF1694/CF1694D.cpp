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

const int N = 2e5 + 1;
int ans, x[N][2], y[N];
vector<int> e[N];

void dfs(int c) {
    y[c] = 0;
    for (int i : e[c]) {
        dfs(i);
        y[c] = min(x[c][1], y[c] + y[i]);
    }
    if (y[c] < x[c][0]) {
        ++ans;
        y[c] = x[c][1];
    }
}

void solve() {
    int n, l, r, p;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        e[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> x[i][0] >> x[i][1];
    ans = 0;
    dfs(1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}