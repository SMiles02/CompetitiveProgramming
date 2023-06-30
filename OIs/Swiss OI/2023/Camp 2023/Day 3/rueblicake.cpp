#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    ll a[n], l = 0, r = 1e15, m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        ll ans = 0;
        for (int i = 0; i < n; ++i)
            ans += a[i] / m;
        if (ans < k)
            r = m - 1;
        else
            l = m;
    }
    cout << l;
    return 0;
}