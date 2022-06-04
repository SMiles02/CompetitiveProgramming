#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 12;
int n, a[N][2];
double dp[1 << N][N][N], d[N][N], ans[1 << N];

ll sq(ll x) {
    return x * x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = sqrt(sq(abs(a[i][0] - a[j][0])) + sq(abs(a[i][1] - a[j][1])));
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                dp[i][j][k] = 1e9;
        if (__builtin_popcount(i) == 1) {
            for (int j = 0; j < n; ++j)
                if (i & (1 << j))
                    dp[i][j][j] = 0;
        }
        else {
            for (int j = 0; j < n; ++j)
                if (i & (1 << j))
                    for (int k = 0; k < n; ++k)
                        if (i & (1 << k))
                            for (int l = 0; l < n; ++l)
                                if ((i & (1 << l)) && k != j && k != l)
                                    dp[i][j][k] = min(dp[i][j][k], dp[i ^ (1 << k)][j][l] + d[l][k]);
        }
        ans[i] = 1e9;
        if (__builtin_popcount(i) > 2) {
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    ans[i] = min(ans[i], dp[i][j][k] + d[j][k]);
        }
        for (int j = i; j; j = (j - 1) & i)
            if (__builtin_popcount(j) > 2 && __builtin_popcount(i ^ j) > 2)
                ans[i] = min(ans[i], ans[j] + ans[i ^ j]);
    }
    cout << fixed << setprecision(17) << ans[(1 << n) - 1];
    return 0;
}