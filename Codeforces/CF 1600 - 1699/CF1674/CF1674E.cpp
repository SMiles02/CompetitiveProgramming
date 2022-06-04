#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 1e9, x, y, z;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        x = min(a[i - 1], a[i]);
        y = max(a[i - 1], a[i]);
        if (y >= x * 2)
            ans = min(ans, (y + 1) / 2);
        else
            ans = min(ans, y - x + ((2 * x - y) / 3) * 2 + ((2 * x - y) % 3));
    }
    for (int i = 1; i + 1 < n; ++i)
        ans = min({ans, (a[i - 1] + a[i + 1] + 1) / 2});
    sort(a, a + n);
    ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
    cout << ans << "\n";
    return 0;
}