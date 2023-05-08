#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

bool intersects(ll a, ll b, ll c, ll d) {
    return max(a, c) <= min(b, d);
}

ll max_height(ll a, ll b, ll n) {
    if (n == 0)
        return 0;
    return a * n - max(b * (n - 1), 0ULL);
}

ll how_many_days(ll a, ll b, ll h) {
    ll l = 1, r = 1, m;
    while (max_height(a, b, r) < h)
        r *= 2;
    while (l < r) {
        m = l + (r - l) / 2;
        if (max_height(a, b, m) < h)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

void solve() {
    int q, t, a, b, n;
    cin >> q;
    ll l = 1, r = 1e18;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> n;
            if (intersects(l, r, max_height(a, b, n - 1) + 1, max_height(a, b, n))) {
                l = max(l, max_height(a, b, n - 1) + 1);
                r = min(r, max_height(a, b, n));
                cout << "1 ";
            }
            else
                cout << "0 ";
        }
        else {
            cin >> a >> b;
            if (how_many_days(a, b, l) == how_many_days(a, b, r))
                cout << how_many_days(a, b, l) << " ";
            else
                cout << "-1 ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}