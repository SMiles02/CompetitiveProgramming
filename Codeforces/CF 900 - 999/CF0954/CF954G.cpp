#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 2;
int n, a[N], d;

ll min_cost(ll x) {
    ll ans = 0;
    vector<ll> p(n + 2);
    for (int i = 1; i <= n; ++i) {
        p[max(i - d, 1)] += a[i];
        p[min(i + d, n) + 1] -= a[i];
    }
    for (int i = 1; i <= n; ++i) {
        p[i] += p[i - 1];
        if (p[i] < x) {
            ans += x - p[i];
            p[min(i + d * 2, n) + 1] -= x - p[i];
            p[i] = x;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll k, l = 0, r = 1, m;
    cin >> n >> d >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (min_cost(r) <= k)
        r *= 2;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (min_cost(m) <= k)
            l = m;
        else
            r = m - 1;
    }
    cout << l;
    return 0;
}