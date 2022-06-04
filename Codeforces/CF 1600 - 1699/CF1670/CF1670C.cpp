#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

struct DSU {
    vector<int> pt, rk;
    vector<bool> taken;
    DSU(int n) : pt(n+1), rk(n+1, 1), taken(n + 1, false) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
            if (taken[j])
                taken[i] = true;
        }
    }
};

void solve() {
    int n, cnt = 0;
    cin >> n;
    int a[n + 1], b[n + 1], d[n + 1];
    DSU dsu(n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        dsu.unite(a[i], b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        if (d[i] != 0)
            dsu.taken[dsu.find(a[i])] = true;
    }
    for (int i = 1; i <= n; ++i)
        cnt += (dsu.find(i) == i && dsu.taken[i] == false && dsu.rk[i] > 1);
    cout << binpow(2, cnt) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}