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
            res = (res * a) % 10;
        a = (a * a) % 10;
        b >>= 1;
    }
    return res;
}

const int N = 1e6 + 1;
bitset<N> sieve;
ll cnt[N][10];

void solve() {
    int n, dv = 0, ans = 1;
    cin >> n;
    int a[n];
    vector<ll> v(10);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 10; ++j)
            v[j] += cnt[a[i]][j];
    }
    v[2] -= v[5];
    v[5] = 0;
    for (int i = 1; i < 10; ++i)
        ans = ans * binpow(i, v[i]);
    cout << ans % 10 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i) {
        for (int j = 0; j < 10; ++j)
            cnt[i][j] += cnt[i - 1][j];
        if (!sieve[i]) {
            int tmp = i % 10;
            for (ll j = i; j < N; j *= i)
                for (int k = j; k < N; k += j) {
                    sieve[k] = 1;
                    ++cnt[k][tmp];
                }
        }
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}