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

int n;

ll solve(vector<int> a) {
    vector<ll> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i - 2 >= 0)
            dp[i] = min(dp[i], dp[i - 2] + a[i - 1]);
        if (i - 3 >= 0)
            dp[i] = min(dp[i], dp[i - 3] + a[i - 1] + a[i - 2]);
    }
    return dp[n];
}

vector<int> rotate(vector<int>& v) {
    vector<int> w(n + 1);
    for (int i = 2; i <= n; ++i)
        w[i] = v[i - 1];
    w[1] = v[n];
    return w;
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> v(n + 1), w, x, y, z, a, b, c;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    w = rotate(v);
    x = rotate(w);
    y = rotate(x);
    z = rotate(y);
    a = rotate(z);
    b = rotate(a);
    c = rotate(b);
    cout << min({solve(v), solve(w), solve(y), solve(z), solve(a), solve(b), solve(c)});
    return 0;
}