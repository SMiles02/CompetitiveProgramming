#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9 + 7;

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

const int N = 3003;
int a[N], dp[N][N], sm[N][N], p[N][N], smP[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0, l, r, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j < i; ++j) {
            dp[i][j] = sm[i][j] = 1;
            dp[i][j] = add(dp[i][j], p[j][j - 1]);
            p[i][j] = add(p[i][j - 1], dp[i][j]);
            if (j > 1) {
                if (a[j] - a[j - 1] > a[i] - a[j]) {
                    sm[i][j] = add(sm[i][j], add(smP[j][j - 1], p[j][j - 1]));
                    cout << "cock\n";
                }
                else if (a[j] - a[1] <= a[i] - a[j])
                    sm[i][j] = add(sm[i][j], smP[j][j - 1]);
                else {
                    l = 1;
                    r = j - 1;
                    while (l < r) {
                        m = l + (r - l) / 2 + 1;
                        if (a[j] - a[m] > a[i] - a[j])
                            l = m;
                        else
                            r = m - 1;
                    }
                    sm[i][j] = add(add(sm[i][j], smP[j][j - 1]), p[j][l]);
                }
            }
            ans = add(ans, sm[i][j]);
            if (i == 4) {
                cout << j << ": " << sm[i][j] << "\n";
            }
            smP[i][j] = add(smP[i][j - 1], sm[i][j]);
        }
        cerr << ans << " ";
    }
    cout << ans;
    return 0;
}