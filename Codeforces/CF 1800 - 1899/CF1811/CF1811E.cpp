#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;

ll ok_cnt(ll x) {
    ll cur = INF, cnt = 0, y = x;
    bool ok = true;
    while (cur > 0) {
        if (cur <= y) {
            if (x / cur == y / cur)
                cnt = x / cur - (x / cur > 4) - 1;
            else
                cnt = cnt * 9 + 8 + (x / cur - (x / cur > 4)) * ok;
        }
        ok &= x / cur != 4;
        x %= cur;
        cur /= 10;
    }
    return cnt + ok;
}

void solve() {
    ll k, l = 1, r = INF, m;
    cin >> k;
    while (l < r) {
        m = l + (r - l) / 2;
        if (ok_cnt(m) >= k)
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}