#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n, x, ans = -1;
    cin >> n;
    vector<int> v(1001, -1e8);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        v[x] = i;
    }
    for (int i = 1; i <= 1000; ++i)
        for (int j = i; j <= 1000; ++j)
            if (gcd(i, j) == 1)
                ans = max(ans, v[i] + v[j]);
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