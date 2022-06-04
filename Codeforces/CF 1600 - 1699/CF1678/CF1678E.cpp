#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1) {
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
        }
    }
};

void solve() {
    int n;
    long long ans = 0;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    DSU dsu(n);
    vector<int> v;
    deque<int> d, e;
    for (int i = 0; i < n; ++i)
        dsu.unite(a[i], b[i]);
    for (int i = 1; i <= n; ++i) {
        d.push_back(i);
        e.push_front(i);
    }
    for (int i = 1; i <= n; ++i)
        if (dsu.find(i) == i && dsu.rk[i] > 1)
            v.push_back(dsu.rk[i]);
    for (int i : v) {
        i -= i & 1;
        vector<int> w;
        for (int j = 0; j < i; ++j) {
            if (j & 1) {
                w.push_back(d.back());
                d.pop_back();
            }
            else {
                w.push_back(e.back());
                e.pop_back();
            }
        }
        for (int j = 1; j < i; ++j)
            ans += abs(w[j] - w[j - 1]);
        ans += abs(w[0] - w[i - 1]);
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