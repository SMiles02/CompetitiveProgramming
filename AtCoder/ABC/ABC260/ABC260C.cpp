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

ll cnt[11][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    cnt[n][0] = 1;
    for (int i = n; i > 1; --i) {
        cnt[i][1] += cnt[i][0] * x;
        if (i > 0) {
            cnt[i - 1][0] += cnt[i][0] + cnt[i][1];
            cnt[i - 1][1] += cnt[i][1] * y;
        }
        // cout << cnt[i][0] << " " << cnt[i][1] << "\n";
    }
    cout << cnt[1][1];
    return 0;
}