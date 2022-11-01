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
    int n, k;
    cin >> n >> k;
    ll p[n + 1], a[n + 1];
    for (int i = n - k + 1; i <= n; ++i)
        cin >> p[i];
    for (int i = n; i > n - k + 1; --i)
        a[i] = p[i] - p[i - 1];
    if (n == k) {
        a[1] = p[1];
        for (int i = 2; i <= n; ++i)
            if (a[i] < a[i - 1]) {
                cout << "NO\n";
                return;
            }
        cout << "YES\n";
        return;
    }
    if (k == 1) {
        cout << "YES\n";
        return;
    }
    for (int i = n - 1; i > n - k + 1; --i)
        if (a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    if (p[n - k + 1] <= 1LL * (n - k + 1) * a[n - k + 2])
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