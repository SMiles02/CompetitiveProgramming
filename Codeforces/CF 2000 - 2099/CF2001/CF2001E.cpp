#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1005;
int n, k, MOD;
int choose[N][N], p[N][N];

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

int sub(int a, int b) { return add(a, MOD - b); }

/**
n - i: 
1: 1
2: 3
3: 
**/

void solve() {
    cin >> n >> k >> MOD;
    for (int i = 0; i <= n + k; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == 0 || i == j) {
                choose[i][j] = 1;
            }
            else {
                choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
            }
            if (0 <= i - 1 && 0 <= j - 1) {
                p[i][j] = add(p[i - 1][j - 1], choose[i][j]);
            }
            else {
                p[i][j] = choose[i][j];
            }
        }
    }
    vector<int> dp(k + 1);
    dp[k] = 1;
    for (int i = 1; i < n; ++i) {
        vector<int> newdp(k + 1);
        int opt = sub(binpow(2, n - i), 1);
        for (int z = 0; z <= k; ++z) {
            for (int x = 0; x <= z; ++x) {
                int maxy = min(x - 1, z - x);
                newdp[x] = add(newdp[x], mul(dp[z], mul(p[maxy + opt - 1][maxy], 2)));
            }
        }
        swap(dp, newdp);
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = add(ans, dp[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}