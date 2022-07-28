#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, m, x = 0, bg, ans = 1e9, dl;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    for (auto i : s)
        if (x < m && t[x] == i)
            ++x;
    if (x != m) {
        cout << "-1\n";
        return;
    }
    if (n == m) {
        cout << "0\n";
        return;
    }
    vector<int> dp1(m + 2), dp2(m + 2), pt1(m + 2), pt2(m + 2), loc1(m + 2), loc2(m + 2), loc_c1(m + 2), loc_c2(m + 2);
    dp2[m + 1] = 0;
    pt2[m + 1] = bg = n;
    loc2[m + 1] = n;
    loc_c2[m + 1] = 0;
    x = m;
    for (int i = n - 1; i >= 0 && x > 0; --i) {
        if (s[i] == t[x - 1]) {
            pt2[x] = bg;
            dp2[x] = dp2[x + 1] + pt2[x + 1] - pt2[x];
            loc2[x] = i;
            loc_c2[x] = pt2[x] - i;
            // cerr << loc2[x] << " ";
            --x;
        }
        else
            bg = i;
    }
    dp1[0] = 0;
    pt1[0] = bg = -1;
    x = 1;
    dl = 0;
    loc1[0] = -1;
    loc_c1[0] = 0;
    for (int i = 0; i < n && x <= m; ++i) {
        if (s[i] == t[x - 1]) {
            pt1[x] = bg;
            dp1[x] = pt1[x] + 1 + dl;
            loc1[x] = i;
            loc_c1[x] = i - pt1[i];
            ++x;
        }
        else {
            bg = i;
            ++dl;
        }
    }
    bool ok = true;
    for (int i = 0; i < m; ++i)
        ok &= (s[i] == t[i]);
    if (ok) {
        cout << n - m << "\n";
        return;
    }
    cout << "0 1: " << dp2[1] + loc2[1] + loc_c2[1] << "\n";
    ans = min(ans, dp2[1] + loc2[1] + loc_c2[1]);
    for (int i = 0; i <= m; ++i) {
        cout << i << " " << i + 1 << ": " << dp1[i] + dp2[i + 1] + 1 + min(loc_c2[i + 1] + loc2[i + 1] - loc1[i] - 1, loc_c1[i] + 2 * (loc2[i + 1] - loc1[i] - 1)) << "\n";
        ans = min(ans, dp1[i] + dp2[i + 1] + (dp1[i] != 0) + min(loc_c2[i + 1] + loc2[i + 1] - loc1[i] - 1, loc_c1[i] + 2 * (loc2[i + 1] - loc1[i] - 1)));
        if (loc1[i] == loc2[i + 1] - 1) {
            // cout << i << " " << i + 1 << ": " << dp1[i] + dp2[i + 1] + 1 << "\n";
            ans = min(ans, dp1[i] + dp2[i + 1] + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}