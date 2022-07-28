#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
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

int n;

ll get_ans(vector<int> v) {
    int tmp[n + 1], diff[n + 1], ed[n + 1], dn;
    tmp[0] = tmp[1] = 0;
    diff[1] = 0;
    ed[1] = v[1];
    ed[0] = -1e18;
    for (int i = 2; i <= n; ++i) {
        tmp[i] = tmp[i - 1] + max(v[i] - v[i - 1], 0LL);
        diff[i] = v[1] - (v[i] - tmp[i]);
        ed[i] = min(ed[i - 1], (v[i] - tmp[i]));
        // cerr << v[i] << " ";
        cout << diff[i] << " " << tmp[i] << " " << ed[i] << "\n";
    }
    for (int i = n; i >= 1; --i) {

    }
}

void solve() {
    cin >> n;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        w[n - i + 1] = v[i];
    }
    //cout << min(get_ans(v), get_ans(w));
    get_ans(v);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}