#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int getRand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

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

void create() {
    int n = getRand(1, 10), x, c = 0;
    vector<int> v, a(n);
    while (1) {
        if (c == 0 && getRand(1, 5) < 3)
            break;        
        x = 0;
        while (x == 0 || 0 > c + x || c + x >= n)
            x = getRand(-1, 1);
        a[c] += x;
        c += x;
    }
    cout << n << "\n";
    for (int i : a)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 20;
    cout << t << endl;
    while (t--)
        create();
    return 0;
}