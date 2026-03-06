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
    int n, ans;
    cin >> n;
    ans = binpow(2, 1LL * n * n);
    if (n & 1) {
        ans = add(ans, binpow(2, 1LL * (n / 2) * (n / 2 + 1) + 1));
        ans = add(ans, binpow(2, 1LL * (n / 2) * (n / 2 + 1) + 1));
    }
    else {
        ans = add(ans, binpow(2, 1LL * (n / 2) * (n / 2)));
        ans = add(ans, binpow(2, 1LL * (n / 2) * (n / 2)));
    }
    ans = add(ans, binpow(2, (1LL * n * n + 1) / 2));
    cout << dv(ans, 4);
    return 0;
}