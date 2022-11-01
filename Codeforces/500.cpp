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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size(), ans = 1e9, cur, q;
    bool flag;
    for (int i = 0; i < (1 << n); ++i) {
        cur = 0;
        flag = false;
        for (int j = 0; j < n; ++j)
            if (((1 << j) & i)) {
                if (cur == 0 && s[j] == '0')
                    flag = true;
                cur *= 10;
                cur += (s[j] - '0');
            }
        q = sqrt(cur);
        if (q * q == cur && !flag && cur > 0) {
            // cout << i << " " << cur << " " << n - __builtin_popcount(i) << "\n";
            ans = min(ans, n - __builtin_popcount(i));
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans;
    return 0;
}