#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int sub(int a, int b) { return add(a, MOD - b); }

const int N = 5005;
int n, k, dp[N][N], tmp[N], maxh[N];
vector<int> e[N];

void dfs(int c, int p) {
    dp[c][0] = 1;
    for (int x : e[c]) {
        if (x == p) { continue; }
        dfs(x, c);
        for (int i = 0; i <= max(maxh[c], maxh[x] + 1); ++i) {
            tmp[i] = 0;
        }
        for (int i = 0; i <= min(maxh[c], k); ++i) {
            for (int j = 0; j <= min(maxh[x], k); ++j) {
                if (i + j + 1 <= k) {
                    tmp[max(i, j + 1)] = add(tmp[max(i, j + 1)], mul(dp[c][i], dp[x][j]));
                }
                tmp[i] = add(tmp[i], mul(dp[c][i], dp[x][j]));
            }
        }
        for (int i = 0; i <= max(maxh[c], maxh[x] + 1); ++i) {
            dp[c][i] = tmp[i];
        }
        maxh[c] = max(maxh[c], maxh[x] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = add(ans, dp[1][i]);
    }
    cout << ans;
    return 0;
}