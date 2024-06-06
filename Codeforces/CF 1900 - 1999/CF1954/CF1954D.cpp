#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353;

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

const int N = 5005;
int dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= v[i]; ++j) {
            ans = add(ans, mul(dp[j], v[i]));
        }
        for (int j = v[i] + 1; j < N; ++j) {
            ans = add(ans, mul((v[i] + j + 1) / 2, dp[j]));
        }
        for (int j = N - 1; j >= v[i]; --j) {
            dp[j] = add(dp[j], dp[j - v[i]]);
        }
    }
    cout << ans;
    return 0;
}