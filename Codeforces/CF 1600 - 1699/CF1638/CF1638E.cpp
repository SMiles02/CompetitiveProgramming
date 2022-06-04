#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct BIT {
    int n;
    ll rtn = 0;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, ll d) { for (int i=x;i<=n;i+=i&-i) bit[i]+=d; }
    ll query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i) rtn+=bit[i];
        return rtn;
    }
};

const int N = 1e6 + 1;
BIT bit(N);
ll col[N];
set<array<int, 3>> s;

void addRange(int l, int r, int c) {
    s.insert({r, l, c});
    bit.update(l, -col[c]);
    bit.update(r + 1, col[c]);
}

void cleanRange(int l, int r) {
    int x, y, z;
    array<int, 3> a;
    while (s.lower_bound({l, 0, 0}) != s.end()) {
        a = *s.lower_bound({l, 0, 0});
        x = a[1];
        y = a[0];
        z = a[2];
        if (r < x)
            break;
        // l <= y
        // l <= r
        s.erase(a);
        bit.update(x, col[z]);
        bit.update(y + 1, -col[z]);
        if (r + 1 <= y)
            addRange(r + 1, y, z);
        if (x <= l - 1)
            addRange(x, l - 1, z);
    }
}

ll getVal(int x) {
    return bit.query(x) + col[(*s.lower_bound({x, 0, 0}))[2]];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r, c, x;
    cin >> n >> q;
    string op;
    s.insert({n, 1, 1});
    while (q--) {
        cin >> op;
        if (op == "Color") { // stupid American spelling, problemsetter sucks
            cin >> l >> r >> c;
            cleanRange(l, r);
            addRange(l, r, c);
        }
        else if (op == "Add") {
            cin >> c >> x;
            col[c] += x;
        }
        else {
            cin >> x;
            cout << getVal(x) << "\n";
        }
    }
    return 0;
}