#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, N = 2e5+1;
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

void solve() {
    int n, l, r, L = 1, R = 2e9, M, x, y, ans = 0;
    bool flag;
    cin >> n >> l >> r;
    while (L < R) {
        M = L + (R - L) / 2 + 1;
        x = 0;
        y = 0;
        flag = false;
        for (int i = 1; i <= n; ++i) {
            if (i - M < l && i + M > r)
                flag = true;
            else if (i - M < l)
                ++y;
            else if (i + M > r)
                ++x;
        }
        if (flag || max(x, y) > (n + 1) / 2)
            R = M - 1;
        else
            L = M;
    }
    x = 0;
    y = 0;
    for (int i = 1; i <= n; ++i) {
        if (i - L < l && i + L > r)
            flag = true;
        else if (i - L < l)
            ++y;
        else if (i + L > r)
            ++x;
    }
    while (L > 0 && (x > 0 || y > 0)) {
        if (n & 1) {
            if (max(x, y) == (n + 1) / 2)
                ans = add(ans, 1);
            else {
                ans = add(ans, C(n - x - y, (n + 1) / 2 - x));
                ans = add(ans, C(n - x - y, (n + 1) / 2 - y));
            }
        }
        else
            ans = add(ans, C(n - x - y, n / 2 - x));
        x = max(x - 1, 0);
        y = max(y - 1, 0);
        --L;
    }
    if (n & 1)
        ans = add(ans, mul(mul(L, C(n, n / 2)), 2));
    else
        ans = add(ans, mul(L, C(n, n / 2)));
    cout << ans << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}