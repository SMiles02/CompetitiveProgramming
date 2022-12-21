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

const int MX = 1e9, N = 31622;
bitset<N> sieve;
vector<int> v;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i : v) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if (a[j] % i == 0) {
                ++cnt;
                while (a[j] % i == 0)
                    a[j] /= i;
            }
        if (cnt > 1) {
            cout << "YES\n";
            return;
        }
    }
    sort(a, a + n);
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i - 1] && a[i] != 1) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i)
        if (sieve[i] == 0) {
            v.push_back(i);
            for (int j = i * 2; j < N; j += i)
                sieve[j] = 1;
        }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}