#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, ans;
    cin >> n;
    vector<int> a(n + 1), p(n + 2), q(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        q[i] = q[i - 1] + (a[i] >= a[i - 1]);
    }
    for (int i = n - 1; i >= 1; --i) {
        p[i] = p[i + 1] + (a[i] >= a[i + 1]);
    }
    ans = p[1];
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, q[i] + p[i + 1] + 1);
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