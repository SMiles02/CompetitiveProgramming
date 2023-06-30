#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = (1 << 19) + 3;
int a[N], p[N], f[N];

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

int C(int n, int k) { return dv(f[n], mul(f[k], f[n - k])); }

void calc_factorials() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, n, ans = 1;
    cin >> k;
    n = 1 << k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= k; ++i) {
        int cur = 0;
        for (int j = 0; j < n; j += 1 << i) {
            int cnt_big = 0, cnt_small = 0, cnt_blank = 0;
            bool blank = true;
            for (int x = j; x < j + (1 << i); ++x) {
                if (a[x] == -1)
                    ++cnt_blank;
                else if (a[x] > (1 << (k - i)))
                    ++cnt_big;
                else
                    ++cnt_small;
            }
            if (cnt_big == (1 << i)) {
                cout << "0\n";
                return 0;
            }
            cur += min((1 << i) - cnt, );
        }
    }
    return 0;
}