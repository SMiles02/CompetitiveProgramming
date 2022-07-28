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

const int N = 29;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x[3], y[3], c, f, ans = 0;
    for (int i = 0; i < 3; ++i)
        cin >> x[i];
    for (int i = 0; i < 3; ++i)
        cin >> y[i];
    if (x[0] + x[1] + x[2] != y[0] + y[1] + y[2]) {
        cout << 0;
        return 0;
    }
    for (int a = 1; a < N; ++a)
        for (int b = 1; b < N; ++b)
            for (int c = 1; c < N; ++c)
                if (a + b + c == x[0])
                    for (int d = 1; d < N; ++d)
                        if (a + d < y[0])
                            for (int e = 1; e < N; ++e)
                                if (b + e < y[1])
                                    for (int f = 1; f < N; ++f)
                                        if (c + f < y[2] && d + e + f == x[1])
                                            ++ans;
    cout << ans;
    return 0;
}