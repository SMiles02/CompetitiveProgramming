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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    long long ans = 0;
    vector<vector<int>> v(n + 2);
    BIT bit(n);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        ans += bit.query(min(k, n));
        if (k >= i) {
            bit.update(i, 1);
            v[min(k, n + 1)].push_back(i);
        }
        while (!v[i].empty()) {
            bit.update(v[i].back(), -1);
            v[i].pop_back();
        }
    }
    cout << ans;
    return 0;
}