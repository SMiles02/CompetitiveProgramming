#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 2e5 + 1;

int sub(int a, int b) { 
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int n, s, t, p[N], ans[N], eq[N];
vector<int> e[N];

void solve(int c) {
    for (int i : e[c])
        if (i != p[c] && i != t) {
            ans[i] = mul(eq[i], ans[c]);
            solve(i);
        }
}

void dfs(int c) {
    int cur = 1;
    for (int i : e[c])
        if (i != p[c] && i != t) {
            p[i] = c;
            dfs(i);
            cur = sub(cur, dv(eq[i], e[i].size()));
        }
    if (c == s) {
        ans[c] = dv(1, cur);
        solve(c);
        return;
    }
    eq[c] = dv(1, mul(e[p[c]].size(), cur));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s >> t;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(s);
    ans[t] = 1;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}