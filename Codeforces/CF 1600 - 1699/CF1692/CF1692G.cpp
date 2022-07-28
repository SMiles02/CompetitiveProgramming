#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    b[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] < a[i + 1] * 2)
            b[i] = b[i + 1] + 1;
        else
            b[i] = 1;
    }
    for (int i = 0; i < n; ++i)
        ans += (b[i] > k);
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