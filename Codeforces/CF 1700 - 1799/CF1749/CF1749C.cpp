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
    int n, x;
    cin >> n;
    vector<int> f(n + 1), tmp(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++f[x];
    }
    for (int i = n; i >= 1; --i) {
        bool ok = true;
        for (int j = 0; j < n + 1; ++j)
            tmp[j] = f[j];
        for (int j = i; j >= 1; --j) {
            for (int k = j; k >= 0; --k) {
                if (k == 0)
                    ok = false;
                if (tmp[k]) {
                    --tmp[k];
                    break;
                }
            }
            for (int k = 1; k <= j; ++k)
                if (tmp[k]) {
                    --tmp[k];
                    break;
                }
        }
        if (ok) {
            cout << i << "\n";
            return;
        }
    }
    cout << "0\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}