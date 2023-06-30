#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
bitset<N> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> p(n);
    vector<long long> dp(n);
    vector<vector<array<int, 2>>> a(m, vector<array<int, 2>>(n));
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        for (int j = 0; j < n; ++j)
            e[i][j] = 1;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j][0];
            a[i][j][1] = j;
        }
        sort(a[i].begin(), a[i].end());
        bitset<N> less;
        for (int r = 0; r < n;) {
            int l = r;
            while (r < n && a[i][l][0] == a[i][r][0])
                e[a[i][r++][1]] &= less;
            while (l < r)
                less[a[i][l++][1]] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (e[a[0][i][1]][j])
                dp[a[0][i][1]] = max(dp[a[0][i][1]], dp[j]);
        dp[a[0][i][1]] += p[a[0][i][1]];
    }
    sort(dp.begin(), dp.end());
    cout << dp.back() << "\n";
    return 0;
}