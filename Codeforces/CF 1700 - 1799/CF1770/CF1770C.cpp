#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> primes;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    vector<vector<int>> v(20, vector<int>(71, 2));
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < primes[i]; ++j)
            v[i][j] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 20; ++j)
            ++v[j][a[i] % primes[j]];
    }
    sort(a, a + n);
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i - 1]) {
            cout << "NO\n";
            return;
        }
    for (int i = 0; i < 20; ++i) {
        int mn = 2;
        for (int j = 0; j < primes[i]; ++j)
            mn = min(mn, v[i][j]);
        if (mn > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 2; i <= 71; ++i) {
        bool p = true;
        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0)
                p = false;
        if (p)
            primes.push_back(i);
    }
    while (t--)
        solve();
    return 0;
}