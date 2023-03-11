#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = 0;

ll f(int x) {
    return (1LL * x * (x + 1)) / 2;
}

struct DSU {
    vector<int> pt, rk, val;
    DSU(int n) : pt(n), rk(n, 1), val(n) {
        for (int i = 0; i < n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            ans -= f(val[i]) + f(val[j]);
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
            val[i] += val[j];
            ans += f(val[i]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    int h[n];
    ll query_ans[q];
    vector<array<int, 2>> v(n), x(q);
    vector<bool> dn(n);
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        v[i] = {h[i], i};
    }
    for (int i = 0; i < q; ++i) {
        cin >> x[i][0];
        x[i][1] = i;
    }
    sort(v.rbegin(), v.rend());
    sort(x.begin(), x.end());
    for (auto i : x) {
        while (!v.empty() && v.back()[0] <= i[0]) {
            ++ans;
            dsu.val[v.back()[1]] = 1;
            dn[v.back()[1]] = true;
            if (v.back()[1] - 1 >= 0 && dn[v.back()[1] - 1] && h[v.back()[1] - 1] <= i[0])
                dsu.unite(v.back()[1], v.back()[1] - 1);
            if (v.back()[1] + 1 < n && dn[v.back()[1] + 1] && h[v.back()[1] + 1] <= i[0])
                dsu.unite(v.back()[1], v.back()[1] + 1);
            v.pop_back();
        }
        query_ans[i[1]] = ans;
    }
    for (int i = 0; i < q; ++i)
        cout << query_ans[i] << "\n";
    return 0;
}