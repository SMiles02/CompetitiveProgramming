#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

// 998244353
const int MOD = 998244353, K = 100, L = 24;
int k, ad[K][K];
vector<vector<vector<int>>> up(L, vector<vector<int>>(2, vector<int>(K)));
vector<vector<int>> dp(2, vector<int>(K));

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

vector<vector<int>> merge(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(2, vector<int>(K));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < k; ++j)
            for (int p = 0; p < 2; ++p)
                for (int q = 0; q < k; ++q)
                    c[i | p][ad[j][q]] = add(c[i | p][ad[j][q]], mul(a[i][j], b[p][q]));
    // cout << "ok" << endl;
    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < k; ++j)
    //         cout << c[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << endl;
    return c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p, m, x;
    cin >> n >> p >> k;
    for (int i = 0; i < k; ++i)
        up[0][0][i] = p / k;
    for (int i = 1; i <= p % k; ++i)
        ++up[0][0][i];
    cin >> m;
    while (m--) {
        cin >> x;
        --up[0][0][x % k];
        ++up[0][1][x % k];
    }
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
            ad[i][j] = (i + j) % k;
    for (int i = 1; i < L; ++i)
        up[i] = merge(up[i - 1], up[i - 1]);
    dp[0][0] = 1;
    for (int i = 0; i < L; ++i)
        if (n & (1 << i))
            dp = merge(dp, up[i]);
    cout << dp[1][0];
    return 0;
}