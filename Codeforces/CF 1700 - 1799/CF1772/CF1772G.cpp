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
    ll x, y, ans = 0, l, r, m;
    cin >> n >> x >> y;
    ll a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (x + i < a[i]) {
            // gains i, loses (n - i)
            if (i <= n - i) {
                cout << "-1\n";
                return;
            }
            l = 1;
            r = 1e12;
            while (l < r) {
                m = l + (r - l) / 2;
                if (x + m * (i * 2 - n) + i < a[i])
                    l = m + 1;
                else
                    r = m;
            }
            if (x + l * (i * 2 - n) + i + 1 >= y) {
                l = 1;
                while (l < r) {
                    m = l + (r - l) / 2;
                    if (x + m * (i * 2 - n) + i < y)
                        l = m + 1;
                    else
                        r = m;
                }
                ans += l * n;
                x += l * (i * 2 - n);
                ans += y - x;
                break;
            }
            x += l * (i * 2 - n);
            ans += l * n;
        }
        if (x + i + 1 == y) {
            ans += i + 1;
            break;
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