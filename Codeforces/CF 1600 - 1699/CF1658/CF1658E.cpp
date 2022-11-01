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

const int N = 2001;
int a[N][N], x[N * N], y[N * N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, mx1, mn1, mx2, mn2, c, d;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            x[a[i][j]] = i;
            y[a[i][j]] = j;
        }
    vector<string> s(n, string(n, 'G')); // every square is a losing square originally
    s[x[n * n]][y[n * n]] = 'M';
    mx1 = x[n * n] + y[n * n];
    mn1 = x[n * n] + y[n * n];
    mx2 = x[n * n] - y[n * n];
    mn2 = x[n * n] - y[n * n];
    for (int i = n * n - 1; i > 0; --i) {
        c = x[i] + y[i];
        d = x[i] - y[i];
        if (max({abs(mx1 - c), abs(mn1 - c), abs(mx2 - d), abs(mn2 - d)}) <= k) {
            s[x[i]][y[i]] = 'M';
            mx1 = max(mx1, c);
            mn1 = min(mn1, c);
            mx2 = max(mx2, d);
            mn2 = min(mn2, d);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << s[i] << "\n";
    return 0;
}

// ideas:
// n^2 => winning square
// all squares > k from n^2 => losing squares
// no point in going to a weaker square than your oppo
// = instant lose