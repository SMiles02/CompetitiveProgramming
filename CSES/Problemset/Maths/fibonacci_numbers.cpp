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

vector<vector<int>> mmul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < c[0].size(); ++j) {
            for (int k = 0; k < a[0].size(); ++k) {
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n;
    if (n < 2) {
        cout << n;
        return 0;
    }
    n -= 1;
    vector<vector<int>> m = {{0, 1}, {1, 1}}, cur = {{0}, {1}};
    for (int i = 0; i < 60; ++i) {
        if (n & (1LL << i)) {
            cur = mmul(m, cur);
        }
        m = mmul(m, m);
    }
    cout << cur[1][0];
    return 0;
}