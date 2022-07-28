#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 251;
int f[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a,binpow(b,MOD-2)); }

int sub(int a, int b) { return add(a,MOD-b); }

int C(int n, int k) { return dv(f[n],mul(f[k],f[n-k])); }

void calc_factorials() {
    f[0]=1;
    for (int i=1;i<N;++i) f[i]=mul(f[i-1],i);
}

int fun(int x) {
    return mul(mul(x, x + 1), (MOD + 1) / 2);
}

int fun(int l, int r) {
    return sub(fun(r), fun(l - 1));
}

int dp[N][N]; // max edge weight, number of nodes done

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    calc_factorials();
    dp[0][1] = 1;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int t = 1; t < j; ++t)
                dp[i][j] = add(dp[i][j], mul(mul(dp[i - 1][t], binpow(k - i + 1, fun(t - 1, j - 2))), C(n - t, j - t)));
        }
    cout << dp[k][n];
    return 0;
}