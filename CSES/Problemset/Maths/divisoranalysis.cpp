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
    int n, k = 1, ans1 = 1, ans2 = 1, ans3, sqrt = 1, ndm = 1;
    bool is_square = true, not_div_two = true;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        is_square &= a[i][1] % 2 == 0;
        k = mul(k, binpow(a[i][0], a[i][1]));
        sqrt = mul(sqrt, binpow(a[i][0], a[i][1] / 2));
        ans1 = mul(ans1, a[i][1] + 1);
        if (not_div_two && !is_square) {
            ndm = (1LL * ndm * ((a[i][1] + 1) / 2)) % (MOD - 1);
            not_div_two = false;
        }
        else {
            ndm = (1LL * ndm * (a[i][1] + 1)) % (MOD - 1);
        }
        ans2 = mul(ans2, dv(sub(binpow(a[i][0], a[i][1] + 1), 1), a[i][0] - 1));
    }
    if (is_square) {
        ans3 = binpow(sqrt, ndm);
    }
    else {
        ans3 = binpow(k, ndm);
    }
    cout << ans1 << " " << ans2 << " " << ans3;
    return 0;
}