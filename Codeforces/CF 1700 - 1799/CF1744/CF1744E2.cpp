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

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

ll a, b, c, d, ans1, ans2;
deque<array<int, 2>> g;

bool check(ll x, ll y) {
    return (a < x && x <= c && b < y && y <= d && (x * y) % (a * b) == 0);
}

deque<array<int, 2>> fact(int x) {
    deque<array<int, 2>> ret;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            ret.push_back({i, 0});
            while (x % i == 0) {
                ++ret.back()[1];
                x /= i;
            }
        }
    if (x > 1)
        ret.push_back({x, 1});
    return ret;
}

void try_solve(ll s) {
    ll j = (a * b) / gcd(s, a * b), t;
    // cout << s << " " << j << "!\n";
    t = ((b + 1 + j - 1) / j) * j;
    s = ((a + 1 + s - 1) / s) * s;
    if (s <= c && t <= d) {
        ans1 = s;
        ans2 = t;
    }
} 

void rec(int i, ll cur) {
    if (i == g.size()) {
        try_solve(cur);
        return;
    }
    for (int j = 0; j <= g[i][1]; ++j) {
        if (j > 0)
            cur *= g[i][0];
        rec(i + 1, cur);
    }
}

void solve() {
    cin >> a >> b >> c >> d;
    deque<array<int, 2>> e = fact(a), f = fact(b);
    g.clear();
    ans1 = ans2 = -1;
    while (!e.empty() && !f.empty()) {
        if (e.front()[0] == f.front()[0]) {
            g.push_back({e.front()[0], e.front()[1] + f.front()[1]});
            e.pop_front();
            f.pop_front();
        }
        else if (e.front()[0] < f.front()[0]) {
            g.push_back({e.front()[0], e.front()[1]});
            e.pop_front();
        }
        else {
            g.push_back({f.front()[0], f.front()[1]});
            f.pop_front();
        }
    }
    for (auto i : e)
        g.push_back(i);
    for (auto i : f)
        g.push_back(i);
    // for (auto i : g)
    //     cout << i[0] << " " << i[1] << "\n";
    // cout << "---\n";
    if (g.empty()) {
        cout << c << " " << d << "\n";
        return;
    }
    rec(0, 1);
    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}