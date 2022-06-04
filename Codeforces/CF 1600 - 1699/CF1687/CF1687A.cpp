#include <bits/stdc++.h>
using namespace std;

long long f(int x) {
    return (1LL * x * (x - 1)) / 2;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    long long p[n + 1], ans = 0;
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    if (k >= n) {
        cout << p[n] + f(k) - f(k - n) << "\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
        ans = max(ans, p[min(i + k - 1, n)] - p[i - 1] + f(k));
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