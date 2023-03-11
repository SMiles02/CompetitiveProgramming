#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

struct BIT {
    int n, rtn; // rtn might need to be LLed
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};

int dig_sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

void solve() {
    int n, q, t, l, r, x, y;
    cin >> n >> q;
    BIT bit(n);
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            bit.update(l, 1);
            bit.update(r + 1, -1);
        }
        else {
            cin >> x;
            y = bit.query(x);
            x = a[x];
            for (int i = 0; i < min(y, 5); ++i)
                x = dig_sum(x);
            cout << x << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}