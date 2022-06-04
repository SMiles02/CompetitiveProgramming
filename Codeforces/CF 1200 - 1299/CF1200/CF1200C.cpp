#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x[3], q, g, a, b, c, d;
    cin >> x[1] >> x[2] >> q;
    g = gcd(x[1], x[2]);
    while (q--) {
        cin >> a >> b >> c >> d;
        if ((b - 1) / (x[a] / g) == (d - 1) / (x[c] / g))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}