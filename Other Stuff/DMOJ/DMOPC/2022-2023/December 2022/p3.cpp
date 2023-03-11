#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 102;
int n;
ll a[N], x[N], y[N];

bool check(ll k) {
    // k /= n;
    // cout << k << "\n";
    ll p = 0, q = 0;
    for (int i = 1; i <= n; ++i) {
        x[i] = (a[i] % 2 != k % 2);
        y[i] = (k - a[i]) / 2;
        p += x[i];
        q += y[i];
        // cout << x[i] << " " << y[i] << "\n";
    }
    // cout << p << " " << q << "!\n";
    if (p > q)
        return false;
    for (int i = 1; i < n; ++i) {
        ll c = min((q - p) / 3, y[i]);
        p += c * 2;
        q -= c;
        x[i] += c * 2;
        y[i] -= c;
        // cout << x[i] << " " << y[i] << "\n";
    }
    for (int i = 1; i <= n; ++i) {
        x[i] += x[i - 1];
        y[i] += y[i - 1];
        if (y[i] > x[i - 1])
            return false;
    }
    return (p == q);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ll s = 0, x, y, mx = 0, l, r, m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
        mx = max(mx, a[i]);
    }
    x = mx * n;
    for (int i = 0; i < 10; ++i)
        if (x % 3 != s % 3 || (x / n) % 2 != a[n] % 2)
            x += n;
    if (x % 3 != s % 3 || (x / n) % 2 != a[n] % 2) {
        cout << -1;
        return 0;
    }
    x /= n;
    y = 1;
    while ((y * n) % 3 != 0 || y % 2)
        ++y;
    l = 0;
    r = 1;
    while (x + y * r * 2 <= (1LL << 61))
        r *= 2;
    while (l < r) {
        m = l + (r - l) / 2;
        if (check(x + y * m))
            r = m;
        else
            l = m + 1;
    }
    if (check(x + y * l))
        cout << x + y * l;
    else
        cout << -1;
    return 0;
}