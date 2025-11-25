#include <bits/stdc++.h>
using namespace std;

const int N = 1001, INF = 1e9;
int a[N], b[N], dp[N][N];
map<int, int> maps[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> cur;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = m; i > 0; --i) {
        maps[i] = cur;
        cur[b[i]] = i;
    }
    maps[0] = cur;
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = INF;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = n - 1; j >= 0; --j) {
            if (dp[i][j] != INF && maps[dp[i][j]][a[i]] != 0) {
                dp[i][j + 1] = min(dp[i][j + 1], maps[dp[i][j]][a[i]]);
            }
        }
    }
    for (int i = n; i >= 0; --i) {
        if (dp[n][i] != INF) {
            cout << i << "\n";
            vector<int> ans = {};
            int cur_pos = i, cur_i = n;
            while (ans.size() < i) {
                if (dp[cur_i][cur_pos] != dp[cur_i - 1][cur_pos]) {
                    ans.push_back(a[cur_i]);
                    --cur_pos;
                }
                --cur_i;
            }
            reverse(ans.begin(), ans.end());
            for (int j : ans) {
                cout << j << " ";
            }
            return 0;
        }
    }
    return 0;
}