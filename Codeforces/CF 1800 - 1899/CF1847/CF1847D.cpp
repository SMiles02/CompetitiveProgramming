#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q, cnt = 0, on_cnt = 0;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<int> p(n + 1);
    BIT bit(n), ord(n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        while (bit.query(l, r) < r - l + 1) {
            int L = l, R = r, M;
            while (L < R) {
                M = L + (R - L) / 2;
                if (bit.query(L, M) < M - L + 1)
                    R = M;
                else
                    L = M + 1;
            }
            p[L] = ++cnt;
            bit.update(L, 1);
            // cerr << L << " " << p[L] << "\n";
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++on_cnt;
            if (p[i + 1] != 0) {
                ord.update(p[i + 1], 1);
            }
        }
    }
    while (q--) {
        int x;
        cin >> x;
        if (s[x - 1] == '0') {
            s[x - 1] = '1';
            ++on_cnt;
            if (p[x] != 0) {
                ord.update(p[x], 1);
            }
        }
        else {
            s[x - 1] = '0';
            --on_cnt;
            if (p[x] != 0) {
                ord.update(p[x], -1);
            }
        }
        cout << min(on_cnt, cnt) - ord.query(1, min(on_cnt, cnt)) << "\n";
    }
    return 0;
}