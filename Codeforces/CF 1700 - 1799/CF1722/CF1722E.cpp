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

const int N = 1002;
ll a[N][N], p[N][N];

void solve() {
    int n, q, x, y, c, d;
    ll ans;
    cin >> n >> q;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = p[i][j] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a[x][y] += x * y;
    }
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            p[i][j] = p[i][j - 1] + a[i][j];
    while (q--) {
        cin >> x >> y >> c >> d;
        if (c == x + 1 || d == y + 1)
            cout << "0\n";
        else {
            ans = 0;
            for (int i = x + 1; i < c; ++i)
                ans += p[i][d - 1] - p[i][y];
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}