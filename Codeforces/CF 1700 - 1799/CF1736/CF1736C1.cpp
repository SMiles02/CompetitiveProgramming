#include <bits/stdc++.h>
using namespace std;

struct sparse_table {
    int n, l;
    vector<vector<int>> spt;
    sparse_table(int n) : n(n), l(__lg(n) + 2), spt(l, vector<int>(n + 1)) {}
    void update(int i, int x) { spt[0][i] = x; }
    int merge(int x, int y) { return min(x, y); }
    void calc() {
        for (int j = 1; j < l; ++j)
            for (int i = 0; i <= n && i + (1 << j) - 1 <= n; ++i)
                    spt[j][i] = merge(spt[j - 1][i], spt[j - 1][i + (1 << (j - 1))]);
    }
    int query(int l, int r) {
        int tmp = __lg(r - l + 1);
        return min(spt[tmp][l], spt[tmp][r - (1 << tmp) + 1]);
    }
};

void solve() {
    int n, l, r, m;
    long long ans = 0;
    cin >> n;
    int a[n + 1];
    sparse_table spt(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        spt.update(i, a[i] - i);
    }
    spt.calc();
    for (int i = 1; i <= n; ++i) {
        l = i;
        r = n;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (spt.query(i, m) >= 1 - i)
                l = m;
            else
                r = m - 1;
        }
        ans += l - i + 1;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}