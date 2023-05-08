#include <bits/stdc++.h>
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k = 1, ans1 = 1, ans2 = 1, ans3 = 0;
    cin >> n;
    while (n--) {
        int x, p;
        cin >> x >> p;
        k = mul(k, binpow(x, p));
        ans1 = mul(ans1, p + 1);
        ans2 = mul(ans2, dv(sub(binpow(x, p + 1), 1), x - 1));
    }
    // ans1 and ans2 are ok, ans3 doesn't work but formula is right
    ans3 = binpow(k, dv(ans1, 2));
    cout << ans1 << " " << ans2 << " " << ans3;
    return 0;
}