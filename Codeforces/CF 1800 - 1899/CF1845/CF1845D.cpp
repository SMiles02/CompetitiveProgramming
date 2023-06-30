#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    ll s[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll sum = 0;
    s[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += a[i];
        s[i] = max(s[i + 1], sum);
    }
    array<ll, 2> ans = {s[0], 0};
    sum = 0;
    for (int i = 0; i + 1 < n; ++i) {
        sum += a[i];
        ans = max(ans, {sum + s[i + 1], sum});
    }
    cout << ans[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}