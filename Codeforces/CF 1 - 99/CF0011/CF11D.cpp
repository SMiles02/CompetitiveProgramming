#include <bits/stdc++.h>
using namespace std;

const int N = 19;
int n, m;
long long ans, dp[1 << N][N];
bitset<N> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x][y] = e[y][x] = 1;
    }
    for (int i = 1; i < (1 << n); ++i) {
        int x = __lg(i & -i);
        if (__builtin_popcount(i) == 1)
            dp[i][x] = 1;
        for (int y = 0; y < n; ++y)
            if (dp[i][y]) {
                if (e[y][x] && __builtin_popcount(i) > 2)
                    ans += dp[i][y];
                for (int j = x + 1; j < n; ++j)
                    if (e[y][j] && !(i & (1 << j)))
                        dp[i | (1 << j)][j] += dp[i][y];
            }
    }
    cout << ans / 2;
    return 0;
}