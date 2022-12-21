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
    int n, x = 0, y = 0;
    ll ans = 0;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v = {1};
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            ++v.back();
        else
            v.push_back(1);
    }
    for (int i : v)
        ans = max(ans, 1LL * i * i);
    for (int i = 0; i < v.size(); i += 2)
        x += v[i];
    for (int i = 1; i < v.size(); i += 2)
        y += v[i];
    cout << max(ans, 1LL * x * y) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}