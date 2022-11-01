#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b) { return add(a,MOD-b); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l, r, m;
    cin >> n;
    int a[n + 1][3], dp[n + 1], c[n + 1], p[n + 1];
    p[0] = 0;
    a[0][0] = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
        dp[i] = add(dp[i - 1], a[i][0] - a[i - 1][0]);
        c[i] = a[i][0] - a[i][1];
        p[i] = add(p[i - 1], c[i]);
        l = 1;
        r = i;
        while (l < r) {
            m = l + (r - l) / 2;
            if (a[m][0] < a[i][1])
                l = m + 1;
            else
                r = m;
        }
        c[i] = sub(p[i], p[l - 1]);
        p[i] = add(p[i - 1], c[i]);
        if (a[i][2] == 1)
            dp[i] = add(dp[i], c[i]);
    }
    cout << add(dp[n], 1);
    return 0;
}