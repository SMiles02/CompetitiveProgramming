#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(int x) {
    return (1LL * x * (x + 1)) / 2;
}

ll f(int l, int r) {
    return f(r) - f(l - 1);
}

struct BIT {
    int n;
    ll rtn;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n + 1) {}
    void update(int x, ll d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    ll query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    ll query(int x, int y) {
        if (x > y) {
            return 0;
        }
        return query(y) - query(x - 1);
    }
};

const int N = 3e5 + 5;
BIT bit(N);
set<int> s;

int get_prev_harbour(int x) {
    return *(--s.lower_bound(x));
}

int get_next_harbour(int x) {
    return *s.lower_bound(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 2>> x(m);
    vector<int> v(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> x[i][0];
        s.insert(x[i][0]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> x[i][1];
        v[x[i][0]] = x[i][1];
    }
    sort(x.begin(), x.end());
    for (int i = 1; i < m; ++i) {
        bit.update(x[i][0], f(x[i][0] - x[i - 1][0] - 1) * x[i - 1][1]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            int next_harbour = get_next_harbour(a), prev_harbour = get_prev_harbour(a);
            bit.update(next_harbour, f(next_harbour - a - 1) * b - bit.query(next_harbour, next_harbour));
            bit.update(a, f(a - prev_harbour - 1) * v[prev_harbour]);
            s.insert(a);
            v[a] = b;
        }
        else {
            int l, r;
            cin >> l >> r;
            if (l == 1) {
                if (r == 1) {
                    cout << "0\n";
                    continue;
                }
                ++l;
            }
            int a = get_prev_harbour(l), b = get_next_harbour(l), c = get_prev_harbour(r), d = get_next_harbour(r);
            if (a == c) {
                cout << f(b - r, b - l) * v[a] << "\n";
            }
            else {
                cout << f(b - l) * v[a] + f(d - r, d - c - 1) * v[c] + bit.query(b + 1, c) << "\n";
            }
        }
    }
    return 0;
}