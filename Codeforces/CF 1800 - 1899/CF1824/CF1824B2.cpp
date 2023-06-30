#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

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

const int N = 2e5 + 1;
int n, k, f[N], sum, sub[N];
vector<int> e[N];

int C(int n, int k) { return dv(f[n], mul(f[k], f[n - k])); }

void calc_factorials() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
}

void dfs(int c, int p = 0) {
    sub[c] = 1;
    for (int i : e[c])
        if (i != p) {
            dfs(i, c);
            if (sub[i] >= k / 2 && n - sub[i] >= k / 2)
                sum = add(sum, mul(C(sub[i], k / 2), C(n - sub[i], k / 2)));
            sub[c] += sub[i];
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (k & 1) {
        cout << 1;
        return 0;
    }
    dfs(1);
    sum = dv(sum, C(n, k));
    cout << add(sum, 1);
    return 0;
}