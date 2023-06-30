#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1001;
const double EPS = 1e-6;
int a[N], b[N];
double dp[N][N];

double dist(int x, int y) {
    return sqrt(1LL * x * x + 1LL * y * y);
}

double is_equal(double x, double y) {
    return abs(x - y) <= EPS;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w, n, m;
    cin >> w >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dp[i][j] = 1e18;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    vector<array<int, 2>> ans = {{0, 0}};
    dp[0][0] = dist(w, abs(a[0] - b[0]));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (i > 0 && j > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist(w, abs(a[i] - b[j])));
            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(w, abs(a[i] - b[j])));
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist(w, abs(a[i] - b[j])));
            // cout << i << " " << j << ": " << dp[i][j] << "\n";
        }
    int x = n - 1, y = m - 1;
    while (x > 0 || y > 0) {
        if (x > 0 && y > 0 && is_equal(dp[x][y], dp[x - 1][y - 1] + dist(w, abs(a[x] - b[y]))))
            ans.push_back({x--, y--});
        else if (x > 0 && is_equal(dp[x][y], dp[x - 1][y] + dist(w, abs(a[x] - b[y]))))
            ans.push_back({x--, y});
        else if (y > 0 && is_equal(dp[x][y], dp[x][y - 1] + dist(w, abs(a[x] - b[y]))))
            ans.push_back({x, y--});
        else {
            cout << "bruh\n";
            return 0;
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i[0] << "  " << i[1] << "\n";
    return 0;
}

// 5 3 2
// 0 5 10
// 2 8