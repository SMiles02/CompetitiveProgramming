#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 17, M = 501;
int dp[1 << N][M], n, tot;
string s;

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

void build(int x, int y) {
    int k = 0, p = 0;
    if (x == y && s[x] == '?')
        --p;
    while (0 <= x && y < n) {
        if (s[x] == '?') {
            if (s[y] != '?')
                k |= (1 << (s[y] - 'a'));
            ++p;
            ++dp[k][p];
        }
        else if (s[y] == '?') {
            k |= (1 << (s[x] - 'a'));
            ++p;
            ++dp[k][p];
        }
        else if (s[x] == s[y])
            ++dp[k][p];
        else
            return;
        --x;
        ++y;
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> s;
    for (auto i : s)
        tot += (i == '?');
    for (int i = 0; i < n; ++i)
        build(i, i);
    for (int i = 1; i < n; ++i)
        build(i - 1, i);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < (1 << N); ++j)
            if (j & (1 << i))
                for (int k = 0; k < M; ++k)
                    dp[j][k] = add(dp[j][k], dp[j ^ (1 << i)][k]);
    int q, ans, t, x, sz;
    cin >> q;
    while (q--) {
        cin >> s;
        ans = 0;
        t = 0;
        x = binpow(sz, tot - min(M - 1, tot));
        sz = s.size();
        for (auto i : s)
            t += (1 << (i - 'a'));
        for (int k = min(M - 1, tot); k >= 0; --k) {
            ans = add(ans, mul(dp[t][k], x));
            x = mul(x, sz);
        }
        cout << ans << "\n";
    }
    return 0;
}