#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 5;
int a[N], p[N];

int ps(int l, int r) {
    if (l > r) {
        return 0;
    }
    return p[r] - p[l - 1];
}

void solve() {
    int n, k, x, ans = -1e9;
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + a[i - 1];
    }
    for (int i = 0; i <= k; ++i) {
        // cout << ps(1, max(n - i - x, 0)) - ps(max(n - i - x, 1), n - i) << ": [1 " << max(n - i - x, 0) << "] - [" << max(n - i - x + 1, 1) << " " << n - i << "]\n";
        ans = max(ans, ps(1, max(n - i - x, 0)) - ps(max(n - i - x + 1, 1), n - i));
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