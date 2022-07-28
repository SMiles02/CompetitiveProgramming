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

int query(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int ret;
    cin >> ret;
    return ret;
}

void answer(int x) {
    cout << "! " << x << endl;
}

int main() {
    int n, x = 1000;
    cin >> n;
    vector<int> d1(n + 1), d2(n + 1);
    for (int i = 3; i <= n; ++i)
        d1[i] = query(1, i);
    for (int i = 3; i <= n; ++i)
        d2[i] = query(2, i);
    for (int i = 3; i <= n; ++i)
        if (d1[i] == 1 && d2[i] == 1) {
            answer(2);
            return 0;
        }
    for (int i = 3; i <= n; ++i)
        x = min(x, d1[i] + d2[i]);
    if (x != 3) {
        answer(x);
        return 0;
    }
    vector<int> v;
    for (int i = 3; i <= n; ++i)
        if (d1[i] + d2[i] == 3)
            v.push_back(i);
    if (v.size() == 2) {
        int y = query(v[0], v[1]);
        if (y == 1)
            answer(3);
        else
            answer(1);
    }
    else
        answer(1);
    return 0;
}