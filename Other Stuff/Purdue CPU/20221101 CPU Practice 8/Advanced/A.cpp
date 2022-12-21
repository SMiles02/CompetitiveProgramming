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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0) {
        for (int i = 0; i <= c; ++i)
            cout << 1;
        cout << "\n";
        return;
    }
    if (c == 0 && b == 0) {
        for (int i = 0; i <= a; ++i)
            cout << 0;
        cout << "\n";
        return;
    }
    vector<int> v = {0};
    while (b--)
        v.push_back(v.size() & 1);
    for (int i : v) {
        cout << i;
        while (i == 0 && a) {
            cout << 0;
            --a;
        }
        while (i == 1 && c) {
            cout << 1;
            --c;
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}