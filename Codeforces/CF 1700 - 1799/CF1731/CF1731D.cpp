#include <bits/stdc++.h>
using namespace std;

int n, m;

bool check(int k, vector<vector<int>>& a) {
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        int chain = 0;
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] >= k) {
                if (++chain >= k) {
                    b[i][j - k + 1] = b[i - 1][j - k + 1] + 1;
                    if (b[i][j - k + 1] >= k)
                        return true;
                }
            }
            else
                chain = 0;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + (r - l) / 2 + 1;
        if (check(mid, a))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}