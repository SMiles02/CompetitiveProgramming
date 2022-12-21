#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
int f[N], C[N][N], MOD;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans, cur;
    cin >> n >> MOD;
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = mul(f[i - 1], i);
    for (int i = 0; i <= n / 2; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    ans = f[n - 2] * (1 - (n & 1));
    for (int i = 2; i <= (n + 1) / 2; ++i) {
        cur = i - (n & 1);
        for (int j = 0; j <= i - 2; ++j)
            ans = add(ans, mul(cur, mul(f[n - i + j - 1], C[i - 2][j])));
    }
    cout << mul(ans, n) << "\n";
    return 0;
}