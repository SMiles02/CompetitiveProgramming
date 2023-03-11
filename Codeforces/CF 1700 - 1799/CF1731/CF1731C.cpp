#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, p = 0, k;
    long long ans = 0;
    cin >> n;
    vector<int> v(n * 4 + 1);
    v[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        p ^= k;
        ans += i;
        for (int j = 0; j * j <= n * 2; ++j)
            ans -= v[p ^ (j * j)];
        ++v[p];
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