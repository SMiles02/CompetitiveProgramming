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

const int N = 2e5 + 5;
int id[N], eat_time[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, gp = 0, x;
    cin >> n >> k;
    set<array<int, 3>> s; // head, size, gp
    array<int, 3> a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (s.lower_bound({x, 0, 0}) == s.end())
            a = {x, 0, ++gp};
        else {
            a = *s.lower_bound({x, 0, 0});
            s.erase(a);
            a[0] = x;
        }
        id[x] = a[2];
        if (++a[1] == k)
            eat_time[a[2]] = i;
        else
            s.insert(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (eat_time[id[i]] == 0)
            eat_time[id[i]] = -1;
        cout << eat_time[id[i]] << "\n";
    }
    return 0;
}