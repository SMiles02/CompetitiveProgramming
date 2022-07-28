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

const double PI = 3.14159265358979;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double a, b, angle, l;
    int d;
    cin >> a >> b;
    cin >> d;
    l = sqrt(a * a + b * b);
    if (a == 0)
        angle = PI / 2;
    else
        angle = atan(b / a);
    angle += ((PI * 2) / 360) * d;
    while (angle > PI * 2)
        angle -= PI * 2;
    cout << fixed << setprecision(15) << l * cos(angle) << " " << l * sin(angle);
    return 0;
}