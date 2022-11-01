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

const int M = 1e5;
int n, m, a[M];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    if (n == m) {
        cout << n << "\n";
        return;
    }
    sort(a, a + m);
    vector<int> v;
    for (int i = 1; i < m; ++i)
        v.push_back(a[i] - a[i - 1] - 1);
    v.push_back(a[0] - a[m - 1] + n - 1);
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < v.size() && v[i] - i * 4 > 0; ++i) {
        // cerr << v[i] << "\n";
        ++ans;
        ans += max(v[i] - (i * 2 + 1) * 2, 0);
        // cerr << "! " << ans << "\n";
    }
    cout << n - ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}