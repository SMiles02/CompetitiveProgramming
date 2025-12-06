#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    int n;
    vector<int> bit;
    fenwick_tree(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) {
        for (int i = x; i <= n; i += i & -i) {
            bit[i] += d;
        }
    }
    int query(int x) {
        int sum = 0;
        for (int i = x; i; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }
    int query(int x, int y) {
        return query(y) - query(x - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, c = 1;
    long long ans = 0;
    cin >> n >> k;
    vector<int> v(n), w(n);
    map<int, int> m;
    fenwick_tree bit(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        w[i] = v[i];
    }
    sort(w.begin(), w.end());
    m[w[0]] = 1;
    for (int i = 1; i < n; ++i) {
        if (w[i] != w[i - 1]) {
            m[w[i]] = ++c;
        }
    }
    for (int i = 0; i < n; ++i) {
        v[i] = m[v[i]];
        ans += bit.query(v[i] + 1, n);
        bit.update(v[i], 1);
        if (i >= k - 1) {
            cout << ans << " ";
            ans -= bit.query(v[i - k + 1] - 1);
            bit.update(v[i - k + 1], -1);
        }
    }
    return 0;
}