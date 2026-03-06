#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e6 + 1;
int pows[N];

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    pows[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pows[i] = mul(pows[i - 1], m);
        ans = add(ans, pows[__gcd(i, n)]);
    }
    cout << dv(ans, n);
    return 0;
}