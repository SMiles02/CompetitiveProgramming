#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fn(int x, int y) {
    if (x == y)
        return x;
    return 3 - x - y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    int a[n + 1][k];
    map<ll, int> m;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        ll tmp = 0;
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
            tmp = tmp * 3 + a[i][j];
        }
        m[tmp] = i;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            ll tmp = 0;
            for (int K = 0; K < k; ++K)
                tmp = tmp * 3 + fn(a[i][K], a[j][K]);
            if (m[tmp] > j) {
                ++cnt[i];
                ++cnt[j];
                ++cnt[m[tmp]];
            }
        }
    for (int i = 1; i <= n; ++i)
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
    cout << ans << "\n";
    return 0;
}