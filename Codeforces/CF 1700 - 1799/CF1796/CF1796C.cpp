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

void solve() {
    int l, r, k, x = 1, ans, mpl;
    cin >> l >> r;
    k = l;
    while (k * 2 <= r) {
        k *= 2;
        ++x;
    }
    cout << x << " ";
    int lB = l, rB = r, mB;
    mpl = 1 << (x - 1);
    while (lB < rB) {
        mB = lB + (rB - lB) / 2 + 1;
        if (1LL * mB * mpl <= r)
            lB = mB;
        else
            rB = mB - 1;
    }
    ans = lB - l + 1;
    if (mpl >= 2 && 1LL * l * (mpl / 2) * 3 <= r) {
        mpl /= 2;
        mpl *= 3;
        lB = l;
        rB = r;
        while (lB < rB) {
            mB = lB + (rB - lB) / 2 + 1;
            if (1LL * mB * mpl <= r)
                lB = mB;
            else
                rB = mB - 1;
        }
        ans = add(ans, mul(lB - l + 1, x - 1));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}