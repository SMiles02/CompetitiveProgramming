#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int a[N][N];

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            ans += a[i][j] != a[n - i - 1][n - j - 1];
            a[i][j] = a[n - i - 1][n - j - 1];
        }
    if (ans <= k && ((k - ans) % 2 == 0 || n % 2 == 1))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}