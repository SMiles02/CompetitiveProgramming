#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, S = 633;
int cnt[S][N];

void solve() {
    int n, s = 0;
    cin >> n;
    int a[n], b[n];
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    while ((s + 1) * (s + 1) <= n * 2)
        ++s;
    for (int i = 1; i <= s; ++i)
        for (int j = 1; j <= n; ++j)
            cnt[i][j] = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] <= s) {
            for (int j = 1; j <= s; ++j)
                if (0 < a[i] * j - b[i] && a[i] * j - b[i] <= n)
                    ans += cnt[j][a[i] * j - b[i]];
            ++cnt[a[i]][b[i]];
        }
    for (int i = 0; i < n; ++i)
        if (a[i] > s)
            for (int j = 1; j <= s; ++j)
                if (0 < a[i] * j - b[i] && a[i] * j - b[i] <= n)
                    ans += cnt[j][a[i] * j - b[i]];
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