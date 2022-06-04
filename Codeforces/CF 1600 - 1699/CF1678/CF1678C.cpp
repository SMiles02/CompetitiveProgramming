#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
int p[N][N];

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= n; ++j)
            p[i][j] = p[i - 1][j] + (a[i] <= j);
    }
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i < j; ++i)
            ans += 1LL * p[i - 1][a[j]] * (a[i] - p[j][a[i]]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}