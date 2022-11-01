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
    int l, r, ans = 0;
    cin >> l >> r;
    vector<int> v(17), w(17);
    int a[r + 1];
    for (int i = 0; i <= r; ++i) {
        cin >> a[i];
        for (int j = 0; j < 17; ++j)
            if (a[i] & (1 << j))
                ++w[j];
    }
    for (int j = 16; j >= 0; --j)
        if (r & (1 << j)) {
            v[j] += r - (1 << j);
            r -= (1 << j);
            ++v[j];
            for (int k = 0; k < j; ++k)
                v[k] += (1 << (j - 1));
        }
    // for (int j = 0; j < 4; ++j)
    //     cout << v[j] << " ";
    // cout << "\n";
    // for (int j = 0; j < 4; ++j)
    //     cout << w[j] << " ";
    // cout << "\n";
    for (int j = 0; j < 17; ++j)
        if (v[j] != w[j])
            ans ^= (1 << j);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}