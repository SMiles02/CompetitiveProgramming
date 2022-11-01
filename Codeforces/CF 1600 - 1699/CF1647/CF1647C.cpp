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

void print(int a, int b, int c, int d) {
    cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << "\n";
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    if (s[0][0] == '1') {
        cout << "-1\n";
        return;
    }
    cout << n * m << "\n";
    for (int i = 0; i < n; ++i)
        for (int j = m - 1; j > 0; --j)
            if (s[i][j] == '1')
                print(i, j - 1, i, j);
    for (int i = n - 1; i > 0; --i)
        if (s[i][0] == '1')
            print(i - 1, 0, i, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '0')
                print(i, j, i, j);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}