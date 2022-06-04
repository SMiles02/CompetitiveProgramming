// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+7;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int ans;
bool flag;
ll b, q, y, c, r, z;

void check(ll g) {
    ll p = (r * g) / q;
    if (gcd(p, q) != g)
        return;
    // p, q <= r
    if (c - r < b || b + q * (y - 1) < c + r * z) {
        flag = true;
        return;
    }
    // cerr << p << " " << g << "\n";
    // cerr << r / p << "\n";
    ans = add(ans, mul(r / p, r / p));
}

void solve() {
    cin >> b >> q >> y;
    cin >> c >> r >> z;
    if (c < b || b + q * (y - 1) < c + r * (z - 1)  || (c - b) % q != 0 || q > r || r % q != 0) {
        cout << "0\n";
        return;
    }
    ans = 0;
    flag = false;
    for (int i = 1; i * i <= r; ++i)
        if (r % i == 0) {
            check(i);
            if (i * i != r)
                check(r / i);
        }
    if (flag)
        ans = -1;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}