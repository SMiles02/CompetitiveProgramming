#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans, cur, x, y;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n < 3) {
        cout << "0\n";
        return;
    }
    ans = n - 1;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
                x = a[j] - a[i];
                y = j - i;
                cur = 0;
                for (int k = 0; k < n; ++k)
                    if ((a[j] - a[i]) * (k - i) != (a[k] - a[i]) * (j - i))
                        ++cur;
                ans = min(ans, cur);
            }
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