#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n, rtn; // rtn might need to be LLed
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void add(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};

int n;

int find_next(int cur, int nxt, BIT& bit) {
    int l = cur + 1, r = n, m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (bit.query(m) < bit.query(cur) + nxt)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, x, cur = 0, nxt, dn = 0;
    cin >> n >> k;
    ++k;
    BIT bit(n);
    for (int i = 1; i <= n; ++i)
        bit.add(i, 1);
    nxt = k;
    while (dn < n) {
        if (cur == 0) {
            if (nxt % bit.query(n) == 0)
                x = find_next(0, bit.query(n), bit);
            else
                x = find_next(0, nxt % bit.query(n), bit);
            ++dn;
            cur = x;
            cout << x << " ";
            bit.add(x, -1);
            nxt = k;
        }
        else if (bit.query(n) - bit.query(cur) < nxt) {
            nxt -= bit.query(n) - bit.query(cur);
            cur = 0;
        }
        else {
            ++dn;
            x = find_next(cur, nxt, bit);
            cur = x;
            cout << x << " ";
            bit.add(x, -1);
            nxt = k;
        }
    }
    return 0;
}