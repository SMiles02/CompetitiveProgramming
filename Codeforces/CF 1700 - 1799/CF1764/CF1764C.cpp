#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans = n / 2;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; ++i)
        if (a[i - 1] != a[i])
            ans = max(ans, 1LL * i * (n - i));
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