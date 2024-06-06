#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, d, cur = 1, tot = 1, ans = 0, cnt = 0;
    cin >> n >> m >> d;
    int a[m + 2];
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    a[0] = 1;
    a[m + 1] = n + 1;
    for (int i = 1; i <= m; ++i) {
        if (a[i] != a[i - 1]) {
            tot += (a[i] - a[i - 1] - 1) / d + 1;
        }
    }
    tot += (a[m + 1] - a[m] - 1) / d;
    for (int i = 1; i <= m; ++i) {
        cur = (a[i + 1] - a[i] - 1) / d - (a[i + 1] - a[i - 1] - 1) / d;
        if (a[i] != a[i - 1]) {
            cur += (a[i] - a[i - 1] - 1) / d + 1;
        }
        if (ans < cur) {
            ans = cur;
            cnt = 1;
        }
        else if (ans == cur) {
            ++cnt;
        }
    }
    cout << tot - ans << " " << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}