#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1e6 + 1;
int f[N];

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
    int n, k, cur = 0, cnt = 0;
    cin >> n;
    if (n & 1) {
        cout << 0;
        return 0;
    }
    string s;
    cin >> s;
    k = s.size();
    for (auto i : s) {
        if (i == '(') {
            ++cur;
            ++cnt;
        }
        else {
            --cur;
            if (cur < 0) {
                cout << 0;
                return 0;
            }
        }
    }
    calc_factorials();
    cout << sub(C(n - k, n / 2 - cnt), C(n - k, n / 2 - (k - cnt) + 1));
    return 0;
}