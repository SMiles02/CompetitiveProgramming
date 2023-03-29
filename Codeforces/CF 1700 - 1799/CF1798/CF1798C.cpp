#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    int a[n], b[n], l = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    ll cur = 1, tmp;
    for (int r = 0; r < n; ++r) {
        tmp = lcm(cur, b[r]);
        bool ok = true;
        if ((1LL * a[r] * b[r]) % tmp)
            ok = false;
        if (cur != tmp)
            for (int k = l; k < r; ++k)
                if ((1LL * a[k] * b[k]) % tmp)
                        ok = false;
        if (ok)
            cur = tmp;
        else {
            ++ans;
            l = r;
            cur = b[r];
        }
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}