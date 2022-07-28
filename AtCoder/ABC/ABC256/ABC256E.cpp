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

struct person {
    int id;
    ll pain;
    bool operator<(const person& rhs) const {
        return pain > rhs.pain;
    }
};

const int N = 2e5 + 1;
int x[N], score[N], c[N];
ll oof[N];
bitset<N> dn;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        ++score[x[i]];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        oof[x[i]] += c[i];
    }
    priority_queue<person> pq;
    for (int i = 1; i <= n; ++i)
        pq.push({i, oof[i]});
    while (!pq.empty()) {
        person p = pq.top();
        pq.pop();
        if (oof[p.id] != p.pain)
            continue;
        ans += oof[p.id];
        dn[p.id] = 1;
        if (!dn[x[p.id]]) {
            oof[x[p.id]] -= c[p.id];
            pq.push({x[p.id], oof[x[p.id]]});
        }
    }
    cout << ans;
    return 0;
}