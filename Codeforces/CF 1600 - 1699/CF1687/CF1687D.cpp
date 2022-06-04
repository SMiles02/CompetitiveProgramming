#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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

const int N = 1e6;
int n, a[N];
ll tL, tR;

bool check(int m) {
    ll x;
    tL = max(a[0], m * m) - a[0];
    tR = 1LL * m * m + m - a[0];
    // cout << tL << " " << tR << "\n";
    for (int i = 1; i < n && tL <= tR; ++i) {
        x = sqrt(a[i] + tR);
        tL = max(tL, x * x - a[i]);
        tR = min(tR, x * x + x - a[i]);
        // cout << x << "\n";
        // cout << tL << " " << tR << "\n";
    }
    return (tL <= tR);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // int x = 0;
    // for (int i = 1; i <= 1000; ++i) {
    //     if ((x + 1) * (x + 1) == i) {
    //         cout << i << " is a square!\n";
    //         ++x;
    //     }
    //     if (i * 2 < x * x + (x + 1) * (x + 1))
    //         cout << i << "\n";
    // }
    int l, r, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    l = sqrt(a[0]);
    r = 2e6 + 4;
    // cout << check(8) << "\n";
    // return 0;

    // while (l < r) {
    //     cout << l << " " << r << "\n";
    //     m = l + (r - l) / 2;
    //     if (check(m))
    //         r = m;
    //     else
    //         l = m + 1;
    // }

    for (int i = l; i <= r; ++i)
        if (check(i))
            break;

    // check(l);
    cout << tL;
    return 0;
}