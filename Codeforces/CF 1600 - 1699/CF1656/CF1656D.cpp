// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define db double
#define each(a,x) for (auto& a: x)
using namespace std;

ll to_n(ll x) {
    return (x * (x + 1)) / 2;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

using ul = uint64_t;
ul modMul(ul a, ul b, const ul mod) {
    ll ret = a*b-mod*(ul)((db)a*b/mod);
    return ret+((ret<0)-(ret>=(ll)mod))*mod; }
ul modPow(ul a, ul b, const ul mod) {
    if (b == 0) return 1;
    ul res = modPow(a,b/2,mod); res = modMul(res,res,mod);
    return b&1 ? modMul(res,a,mod) : res;
}

bool prime(ul n) { // not ll!
    if (n < 2 || n % 6 % 4 != 1) return n-2 < 2;
    ul A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n>>s;
    each(a,A) {   // ^ count trailing zeroes
        ul p = modPow(a,d,n), i = s;
        while (p != 1 && p != n-1 && a%n && i--) p = modMul(p,p,n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

ul pollard(ul n) { // return some nontrivial factor of n
    auto f = [n](ul x) { return modMul(x, x, n) + 1; };
    ul x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || gcd(prd, n) == 1) { /// speedup: don't take gcd every it
        if (x == y) x = ++i, y = f(x);
        if ((q = modMul(prd, max(x,y)-min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prd, n);
}
void factor_rec(ul n, map<ul,int>& cnt) {
    if (n == 1) return;
    if (prime(n)) { ++cnt[n]; return; }
    ul u = pollard(n);
    factor_rec(u,cnt), factor_rec(n/u,cnt);
}

void solve() {
    ll n, k, t;
    cin >> n;
    if (n & 1) {
        cout << "2\n";
        return;
    }
    if (__builtin_popcountll(n) == 1) {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i < 31 && to_n(1 << i) <= n; ++i)
        if (to_n(1 << i) % (1 << i) == n % (1 << i)) {
            cout << (1 << i) << "\n";
            return;
        }
    k = n;
    while (1) {
        t = k;
        while (!prime(t))
            t = pollard(t);
        if (to_n(t) % t == n % t) {
            cout << t << "\n";
            return;
        }
        while (k % t == 0)
            k /= t;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}