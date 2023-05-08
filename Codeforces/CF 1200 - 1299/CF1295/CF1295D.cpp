#include <bits/stdc++.h>
#define ll long long
using namespace std;

// since gcd(a + (m - a) + 1, m) = gcd(1, m) and so on, the problem becomes:
// count number of 1 <= x <= m s.t. gcd(x, m) = gcd(a, m)
// => etf of m / gcd(x, m)

ll etf(ll n) {
    ll m = n;
    for (int i = 2; 1LL * i * i <= m; ++i)
        if (m % i == 0) {
            n /= i;
            n *= i - 1;
            while (m % i == 0)
                m /= i;
        }
    if (m > 1) {
        n /= m;
        n *= m - 1;
    }
    return n;
}

void solve() {
    ll a, m;
    cin >> a >> m;
    cout << etf(m / __gcd(a, m)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}