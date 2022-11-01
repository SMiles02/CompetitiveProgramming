#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = 122;
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

int dp[61][3];

void solve() {
    int n;
    cin >> n;
    cout << dp[n][0] << " " << dp[n][1] << " 1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    dp[2][0] = 1;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i = 4; i < 61; i += 2) {
        dp[i][0] = add(C(i - 1, i / 2), dp[i - 2][1]);
        dp[i][1] = add(C(i - 2, i / 2), dp[i - 2][0]);
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}