#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

// used parallel binary search for this because I'm a dumbass

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

int midpoint(int l, int r) {
    return l + (r - l) / 2;
}

void solve() {
    int n, s, q, ans;
    cin >> n >> s;
    ans = n + 1;
    vector<array<int, 2>> seg(s);
    for (int i = 0; i < s; ++i) {
        cin >> seg[i][0] >> seg[i][1];
    }
    cin >> q;
    vector<int> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }
    vector<vector<array<int, 4>>> pbs(q);
    for (int i = 0; i < s; ++i) {
        pbs[midpoint(0, q - 1)].push_back({0, q - 1, seg[i][0], seg[i][1]});
    }
    for (int _ = 0; _ < 18; ++_) {
        BIT bit(n);
        // cout << "Run " << _ << "\n";
        for (int i = 0; i < q; ++i) {
            bit.update(a[i], 1);
            for (auto j : pbs[i]) {
                auto [ql, qr, l, r] = j;
                // cout << i << ": " << ql << " " << qr << " " << l << " " << r << "\n";
                int newl, newr;
                if (bit.query(l, r) * 2 > r - l + 1) {
                    // cout << "That worked!\n";
                    ans = min(ans, i);
                    newl = ql;
                    newr = i - 1;
                }
                else {
                    newl = i + 1;
                    newr = qr;
                }
                // cout << newl << " " << newr << "\n";
                if (newl <= newr) {
                    pbs[midpoint(newl, newr)].push_back({newl, newr, l, r});
                }
            }
            pbs[i].clear();
        }
    }
    if (ans > n) {
        ans = -2;
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}