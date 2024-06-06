#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n, rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};

void solve() {
    int n;
    cin >> n;
    BIT win(n), lose(n);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        if (win.query(k) == 0 && lose.query(k) > 0) {
            win.update(k, 1);
        }
        else {
            lose.update(k, 1);
        }
    }
    cout << win.query(n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}