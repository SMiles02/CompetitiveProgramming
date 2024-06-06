#include <bits/stdc++.h>
#define ll long long
using namespace std;

array<ll, 2> sub(array<ll, 2> a, array<ll, 2> b) {
    ll d = (a[1] / __gcd(a[1], b[1])) * b[1];
    array<ll, 2> tmp =  {a[0] * (d / a[1]) - b[0] * (d / b[1]), d};
    ll g = __gcd(tmp[0], tmp[1]);
    return {tmp[0] / g, tmp[1] / g};
}

bool less_than(array<ll, 2> a, array<ll, 2> b) {
    // cerr << a[0] << " " << a[1] << " " << b[0] << " " << b[1] << "\n";
    return a[0] * b[1] < a[1] * b[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y;
    cin >> x >> y >> n;
    array<ll, 2> ans = {0, 1};
    array<ll, 2> diff = {x, y};
    for (int i = 1; i <= n; ++i) {
        ll l = 0, r = 1, m;
        while (less_than({r, i}, {x, y})) {
            l = r;
            r *= 2;
        }
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (less_than({m, i}, {x, y})) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        // cerr << l << " " << i << "\n";
        // cerr << sub({x, y}, {l, i})[0] << " " << sub({x, y}, {l, i})[1] << " " << diff[0] << " " << diff[1] << " !\n";
        // cerr << less_than(sub({x, y}, {l, i}), diff) << "\n";
        if (less_than(sub({x, y}, {l, i}), diff)) {
            // cerr << "moo\n";
            ans = {l, i};
            diff = sub({x, y}, {l, i});
        }
        if (less_than(sub({l + 1, i}, {x, y}), diff)) {
            // cerr << "other moo\n";
            ans = {l + 1, i};
            diff = sub({l + 1, i}, {x, y});
        }
    }
    cout << ans[0] << "/" << ans[1] << "\n";
    return 0;
}