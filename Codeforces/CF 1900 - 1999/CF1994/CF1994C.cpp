#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, rp;
    cin >> n >> k;
    long long sum = (1LL * n * (n + 1)) / 2;
    vector<int> a(n + 1), ans(n + 2);
    vector<long long> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    rp = n;
    for (int i = n; i > 0; --i) {
        if (p[n] - p[i - 1] <= k) {
            continue;
        }
        while (p[rp - 1] - p[i - 1] > k) {
            --rp;
        } 
        ans[i] = ans[rp + 1] + 1;
        sum -= ans[i];
    }
    cout << sum << "\n";
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