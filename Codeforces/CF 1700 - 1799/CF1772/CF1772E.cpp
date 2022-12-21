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
    int n, x = 0, y = 0, z = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1 && a[i] != n - i)
            ++z;
        else if (a[i] != i + 1)
            ++x;
        else if (a[i] != n - i)
            ++y;
    }
    // cout << x << " " << y << " " << z << "\n";
    // return;
    for (int i = 0; i < n * 3; ++i) {
        if (i & 1) {
            if (y)
                --y;
            else if (z == 0) {
                cout << "Second\n";
                return;
            }
            else if (z <= x)
                --z;
        }
        else {
            if (x)
                --x;
            else if (z == 0) {
                cout << "First\n";
                return;
            }
            else if (z <= y)
                --z;
        }
        // cout << x << " " << y << " " << z << "\n";
    }
    cout << "Tie\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}