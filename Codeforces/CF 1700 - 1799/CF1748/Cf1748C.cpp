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
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll p = 0, ans = 0;
    array<ll, 2> b;
    map<ll, int> m;
    m[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            map<int, int> mp;
            int cnt = 0;
            ll q = 0, mx = 0;
            for (int j = i + 1; j <= n || a[j] == 0; ++j) {
                q += a[j];
                ++mp[q];
            }
            for (auto j : mp)
                if (j.second > cnt) {
                    cnt = j.second;
                    mx = j.first;
                }
            a[i] = b[1] - mx;
        }
        p += a[i];
        ans += m[p]++;
        b = max(b, {m[p], p});
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