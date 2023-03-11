#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 3e5 + 1;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a, binpow(b, MOD - 2)); }

int sub(int a, int b) { return add(a, MOD - b); }

int n, k, p[N], s[N], d[N], ans;
vector<int> e[N];

void dfs(int c) {
    s[c] = p[c];
    for (int i : e[c])
        if (i != d[c]) {
            d[i] = c;
            dfs(i);
            ans = add(ans, mul(k - s[i], s[i]));
            s[c] = add(s[c], s[i]);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        p[x] = 1;
    }
    vector<array<int, 2>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        edges[i] = {x, y};
    }
    dfs(1);
    for (auto i : edges) {
        x = i[0];
        y = i[1];
        if (d[x] != y)
            swap(x, y);
        ans = add(ans, mul(sub(mul(k - s[x] + 1, s[x] - 1), mul(k - s[x], s[x])), mul(mul(p[x], sub(1, p[y])), (MOD + 1) / 2)));
        ans = add(ans, mul(sub(mul(k - s[x] - 1, s[x] + 1), mul(k - s[x], s[x])), mul(mul(p[y], sub(1, p[x])), (MOD + 1) / 2)));
        p[x] = p[y] = mul(add(p[x], p[y]), (MOD + 1) / 2);
    }
    ans = dv(mul(ans, 2), mul(k, k - 1));
    cout << ans;
    return 0;
}