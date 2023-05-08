#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = -1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, x, ans = 0;
    ll s = 0;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<ll> p(n + 2);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
        if (p[i] == INF || (s & 1))
            p[i + 1] = INF;
        else
            p[i + 1] = s / 2;
        s /= 2;
    }
    s = 0;
    for (int i = n; i >= 0; --i) {
        if (abs(s) > 1e10)
            break;
        if (p[i] != INF && abs(p[i] + s) <= k) {
            if (i == n)
                ans += p[i] != 0;
            else
                ++ans;
        }
        s = (s + a[i]) * 2;
    }
    cout << ans;
    return 0;
}