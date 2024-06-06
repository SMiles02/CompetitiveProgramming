#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, long long b) {
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
    int n, b = 1, two = 2;
    long long k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        two = binpow(two, k);
        b = (1LL * b * k) & 1;
    }
    two = dv(two, 2);
    cout << dv(sub(two, binpow(MOD - 1, b ^ 1)), 3);
    cout << "/";
    cout << two;
    return 0;
}