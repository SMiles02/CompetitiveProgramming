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
    ll ans = 0, cur;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> v, w;
    v = w = {1};
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            ++v.back();
        else
            v.push_back(1);
        if (t[i] == t[i - 1])
            ++w.back();
        else
            w.push_back(1);
    }
    if (s[0] != t[0] || s[n - 1] != t[n - 1] || v.size() != w.size()) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i + 1 < v.size(); ++i) {
        cur = v[i] - w[i];
        ans += abs(cur);
        v[i] -= cur;
        v[i + 1] += cur;
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