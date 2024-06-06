#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

ll f(int n) {
    return (1LL * n * (n + 1)) / 2;
}

ll f(int l, int r) {
    return f(r) - f(l - 1);
}

ll g(int l, int r) {
    ll tmp = f(l / 2 + 1, r / 2 + 1) * 2;
    if (l & 1) {
        tmp -= l / 2 + 1;
    }
    if (r % 2 == 0) {
        tmp -= r / 2 + 1;
    }
    return tmp;
}

ll calc_range_contrib(int l, int r, int oc, int ec) {
    int o, e;
    o = e = (r - l + 1) / 2;
    if ((r - l + 1) & 1) {
        if (l & 1) {
            ++o;
        }
        else {
            ++e;
        }
    }
    // cerr << l << " " << r << ": " << g(l, r) - 1LL * o * ec - 1LL * e * oc << "\n";
    return g(l, r) - 1LL * o * ec - 1LL * e * oc;
}

void solve() {
    int n, c, oc = 0, ec = 0, x;
    ll ans = 0;
    cin >> n >> c;
    vector<int> s(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    s[n] = c + 1;
    ans = f(s[0]);
    for (int i = 0; i < n; ++i) {
        oc += s[i] & 1;
        ec += 1 - (s[i] & 1);
        if (s[i] + 1 < s[i + 1]) {
            ans += calc_range_contrib(s[i] + 1, s[i + 1] - 1, oc, ec);
        }
    }
    x = c;
    for (int i = n - 1; i >= 0; --i) {
        // (c - s[i], c) = c * 2 - s[i]
        // [x + 1, c * 2 - s[i]]
        int o, e, l = x + 1, r = c * 2 - s[i];
        o = e = (r - l + 1) / 2;
        if ((r - l + 1) & 1) {
            if (l & 1) {
                ++o;
            }
            else {
                ++e;
            }
        }
        ans += g(s[i], c * 2 - x - 1) - 1LL * o * ec - 1LL * e * oc;
        oc += s[i] & 1;
        ec += 1 - (s[i] & 1);
        x = c * 2 - s[i];
    }
    if (x < c * 2) {
        ans += g(0, c * 2 - x - 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}