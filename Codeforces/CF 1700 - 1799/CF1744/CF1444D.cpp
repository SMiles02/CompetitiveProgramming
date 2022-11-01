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
    int n, cnt = 0, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        while (k % 2 == 0) {
            k /= 2;
            ++cnt;
        }
        int tmp = i, cur = 0;
        while (tmp % 2 == 0) {
            ++cur;
            tmp /= 2;
        }
        v[i - 1] = cur;
    }
    if (cnt >= n) {
        cout << "0\n";
        return;
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; ++i) {
        cnt += v[i];
        // cout << cnt << "\n";
        if (cnt >= n) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}