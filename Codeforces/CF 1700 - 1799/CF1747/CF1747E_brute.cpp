#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9 + 7, N = 50;
int f[N], dp[N * 2 + 2][N + 1][N + 1];

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

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= N * 2 + 1; ++i)
        ans = add(ans, mul(dp[i][n][m], i));
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    dp[1][0][0] = 1;
    for (int l = 2; l <= N * 2 + 1; ++l)
        for (int i = 0; i <= N; ++i)
            for (int j = 0; j <= N; ++j)
                for (int p = 0; p <= i; ++p)
                    for (int q = 0; q <= j; ++q)
                        if (p + q < i + j)
                            dp[l][i][j] = add(dp[l][i][j], dp[l - 1][p][q]);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}