// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (char a = 'a'; a <= 'z'; ++a)
        for (char b = 'a'; b <= 'z'; ++b)
            for (char c = 'a'; c <= 'z'; ++c)
                for (char e = 'a'; e <= 'z'; ++e) {
                    set<char> s;
                    s.insert(a);
                    s.insert(b);
                    s.insert(c);
                    s.insert(e);
                    if (!(s.count('d') || s.count('i') || s.count('e') || s.count('s') || s.count('p') || s.count('o') || !s.count('a') || !s.count('u') || !s.count('t') || a == 'a' || e == 'u' || e == 't' || e != 'a'))
                        cout << a << b << c << "r" << e << endl;
                }
    return 0;
}