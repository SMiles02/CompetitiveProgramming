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

const int N = 3e5 + 1;
int ans[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k > n / 2) {
        cout << "-1\n";
        return 0;
    }
    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    for (int i = n; i + k > n; --i) {
        ans[i - k] = i;
        s.erase(i - k);
    }
    for (int i = 1; i + k <= n; ++i) {
        if (i - *s.begin() >= k) {
            ans[*s.begin()] = i;
            s.erase(s.begin());
        }
        else {
            ans[*s.lower_bound(i + k)] = i;
            s.erase(s.lower_bound(i + k));
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}