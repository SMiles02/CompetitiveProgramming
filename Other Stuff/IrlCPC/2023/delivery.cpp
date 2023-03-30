#include <bits/stdc++.h>
using namespace std;

// post-contest solution notes:
// - notice the two trips will never intersect (aside from trivially at the start and end)
// - thus we can store their dp-value as two cells on each diagonal
// - for each diagonal, store the cells from top to bottom
// i.e. for the 5-diagonal, store them as:
// (1, 4), (2, 3), (3, 2), (4, 1)
// and assign them these values (stored in val here)
// in this case the values would be [0, 3]
// - do the dp!

const int N = 300, INF = -1e9;
int a[N][N], val[N][N], p[N * 2], n; 

vector<int> dx = {-1, 0};
vector<int> dy = {0, -1};

bool ok(int x) {
    return 1 <= x && x <= n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, x, y, z;
    cin >> n;
    cin >> m;
    assert(n != 1); // stupid check because problemsetter is bad
    while (m--) {
        cin >> x >> y >> z;
        // another problemsetter being bad moment
        assert(!((x == 0 && y == 0) || (x == n - 1 && y == n - 1)));
        a[x + 1][y + 1] = z;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            val[i][j] = p[i + j]++;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    dp[0][1] = a[1][2] + a[2][1];
    for (int sm = 4; sm < n * 2; ++sm) {
        vector<vector<int>> new_dp(n, vector<int>(n, INF));
        for (int i = 1; i <= n; ++i)
            if (ok(sm - i)) {
                int j = sm - i;
                for (int x = i + 1, y = j - 1; ok(x) && ok(y); ++x, --y)
                    for (int d = 0; d < 2; ++d)
                        if (ok(i + dx[d]) && ok(j + dy[d]))
                            for (int e = 0; e < 2; ++e)
                                if (ok(x + dx[e]) && ok(y + dy[e]))
                                    new_dp[val[i][j]][val[x][y]] = max(new_dp[val[i][j]][val[x][y]], dp[val[i + dx[d]][j + dy[d]]][val[x + dx[e]][y + dy[e]]] + a[i][j] + a[x][y]);
            }
        swap(dp, new_dp);
    }
    cout << dp[0][1] << "\n";
    return 0;
}