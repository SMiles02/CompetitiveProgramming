#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int MOD = 998244353, N = (1 << 18), H = 120;
int b[H][N], dp[N], hV[N][H], sub[N];

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < H; ++i) {
        b[i][0] = 1;
        b[i][1] = rnd(1000, 1000000);
        for (int j = 2; j < N; ++j)
            b[i][j] = mul(b[i][j - 1], b[i][1]);
    }
    int n, x, y;
    cin >> n;
    n = (1 << n) - 1;
    string s;
    cin >> s;
    s = "?" + s;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < H; ++j)
            hV[i][j] = s[i] - 'A' + 1;
        if (i * 2 > n) {
            dp[i] = 1;
            sub[i] = 1;
        }
        else {
            sub[i] = sub[i * 2] * 2 + 1;
            bool same = true;
            for (int j = 0; j < H; ++j)
                if (hV[i * 2][j] != hV[i * 2 + 1][j])
                    same = false;
            if (same)
                dp[i] = mul(dp[i * 2], dp[i * 2 + 1]);
            else
                dp[i] = mul(2, mul(dp[i * 2], dp[i * 2 + 1]));
            for (int j = 0; j < H; ++j) {
                x = hV[i * 2][j];
                y = hV[i * 2 + 1][j];
                if (x < y)
                    swap(x, y);
                hV[i][j] = mul(hV[i][j], b[j][sub[i * 2]]);
                hV[i][j] = add(hV[i][j], x);
                hV[i][j] = mul(hV[i][j], b[j][sub[i * 2 + 1]]);
                hV[i][j] = add(hV[i][j], y);
            }
        }
    }
    cout << dp[1];
    return 0;
}