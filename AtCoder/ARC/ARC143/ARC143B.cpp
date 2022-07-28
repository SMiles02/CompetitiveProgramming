#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 505 * 505;
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int n, ans, cur;
    cin >> n;
    ans = f[n * n];
    for (int i = 1; i <= n * n; ++i)
        if (n <= i && i <= n * n - n + 1) {
            cur = n * n;
            cur = mul(cur, C(i - 1, n - 1));
            cur = mul(cur, C(n * n - i, n - 1));
            cur = mul(cur, binpow(f[n - 1], 2));
            cur = mul(cur, f[(n - 1) * (n - 1)]);
            ans = sub(ans, cur);
        }
    cout << ans;
    return 0;
}