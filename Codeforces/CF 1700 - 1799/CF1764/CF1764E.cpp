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
    int b[n], m[n];
    array<int, 2> a[n];
    cin >> a[n - 1][0] >> a[n - 1][1];
    for (int i = 0; i < n - 1; ++i)
        cin >> a[i][0] >> a[i][1];
    sort(a, a + n - 1);
    b[0] = a[0][0];
    m[0] = a[0][1];
    for (int i = 1; i < n; ++i) {
        b[i] = max(a[i][0] + m[i - 1], min(a[i][0], b[i - 1]) + a[i][1]);
        m[i] = max(m[i - 1], a[i][1]);
    }
    if (b[n - 1] >= k)
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