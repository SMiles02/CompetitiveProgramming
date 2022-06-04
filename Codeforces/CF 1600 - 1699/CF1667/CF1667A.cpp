#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[5000];
ll b[5000];

ll solve(int x) {
    ll cur = 0;
    b[x] = 0;
    for (int i = x - 1; i >= 0; --i) {
        b[i] = (b[i + 1] / a[i] + 1) * a[i];
        cur += b[i] / a[i];
    }
    for (int i = x + 1; i < n; ++i) {
        b[i] = (b[i - 1] / a[i] + 1) * a[i];
        cur += b[i] / a[i];
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 1e18;
    for (int i = 0; i < n; ++i)
        ans = min(ans, solve(i));
    cout << ans;
    return 0;
}