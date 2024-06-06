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

void solve() {
    int n;
    ll k, l = 1, r = 3e12, m;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        ll req = 0;
        for (auto i : a) {
            req += max(m - i, 0ll);
        }
        if (req <= k) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        k -= max(l - a[i], 0ll);
        a[i] = max(a[i], l);
    }
    for (int i = 0; i < k; ++i) {
        ++a[i];
    }
    int cnt = 0;
    sort(a.begin(), a.end());
    for (auto i : a) {
        cnt += i == a[0];
    }
    cout << a[0] * n - cnt + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}