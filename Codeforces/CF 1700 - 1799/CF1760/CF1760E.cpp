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
    ll cur = 0, ans;
    cin >> n;
    vector<int> a(n + 2), o(n + 2), z(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        o[i] = o[i - 1] + (a[i] == 1);
    for (int i = n; i >= 1; --i)
        z[i] = z[i + 1] + (a[i] == 0);
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0)
            cur += o[i - 1];
    ans = cur;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0)
            ans = max(ans, cur - o[i - 1] + z[i + 1]);
        else
            ans = max(ans, cur - z[i + 1] + o[i - 1]);
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