#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, cur = 0;
    long long ans = 0;
    cin >> n;
    vector<int> f(n + 1);
    while (n--) {
        cin >> k;
        ++f[k];
    }
    for (int i : f) {
        ans += ((1LL * i * (i - 1) * cur) / 2) + ((1LL * i * (i - 1) * (i - 2)) / 6);
        cur += i;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}