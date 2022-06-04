// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
bool local = 1;

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

ll query(ll x, ll y) {
    if (local)
        return gcd(x + n, y + n);
    cout << "? " << x << " " << y << endl;
    ll ret;
    cin >> ret;
    return ret;
}

void solve() {
    if (local)
        cin >> n;
    ll qA, md = 0;
    for (int i = 1; i < 31; ++i) {
        qA = query((1LL << (i - 1)) - md, (1LL << (i - 1)) - md + (1LL << i));
        if (qA % (1LL << i))
            md += (1LL << (i - 1));
        // cout << md << endl;
    }
    cout << "! " << md << endl;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}