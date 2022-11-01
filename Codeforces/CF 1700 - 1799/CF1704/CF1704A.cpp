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
    int n, m;
    vector<bool> b(2);
    bool ok = true, cur;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    for (int i = n; i >= n - m; --i) {
        if (s[i] != t[i - n + m]) {
            cur = false;
            // cout << i << " " << i - n + m << "!\n";
            for (int j = i - 1; j >= 0; --j)
                if (s[j] == t[i - n + m]) {
                    s[i] = t[i - n + m];
                    i = j;
                    cur = true;
                    break;
                }
            if (cur == false)
                ok = false;
        }
    }
    // cout << s << "\n";
    // cout << t << "\n";
    for (int i = n - m; i < n; ++i)
        ok &= (s[i] == t[i - n + m]);
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}