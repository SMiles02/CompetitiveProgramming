#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct disjoint_set_union {
    int n;
    vector<int> p, sz, lo, hi;
    vector<ll> a;
    disjoint_set_union(int n) : n(n), p(n), sz(n, 1), lo(n), hi(n), a(n) {
        iota(p.begin(), p.end(), 0);
        iota(lo.begin(), lo.end(), 0);
        iota(hi.begin(), hi.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
            lo[i] = min(lo[i], lo[j]);
            hi[i] = max(hi[i], hi[j]);
            a[i] += a[j];
            // cerr << "merged " << i << " and " << j << endl; 
        }
    }
    int type(int i) {
        if (a[i] < 0) {
            return 1;
        }
        else {
            return 2;
        }
    }
    void check(int i, ll t) {
        i = find_set(i);
        // cerr << "checking " << i << ", val is " << a[i] << ", time is " << t << endl;
        while (lo[i] != 0) {
            // cerr << "entered lo" << endl;
            int j = find_set(lo[i] - 1);
            if (a[i] == 0 || a[j] == 0) {
                unite(i, j);
            }
            else if (type(i) == type(j)) {
                unite(i, j);
                i = find_set(i);
                if (a[i] > 0) {
                    a[i] -= t;
                }
                else {
                    a[i] += t;
                }
            }
            else {
                break;
            }
            i = find_set(i);
            // cerr << "new size is " << a[i] << endl;
        }
        while (hi[i] != n - 1) {
            // cerr << "entered hi " << endl;
            int j = find_set(hi[i] + 1);
            if (a[i] == 0 || a[j] == 0) {
                unite(i, j);
            }
            else if (type(i) == type(j)) {
                unite(i, j);
                i = find_set(i);
                if (a[i] > 0) {
                    a[i] -= t;
                }
                else {
                    a[i] += t;
                }
            }
            else {
                break;
            }
            i = find_set(i);
            // cerr << "new size is " << a[i] << endl;
        }
        // cerr << "all done in here, new size is " << a[i] << endl;
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
    ll get_val(int i) {
        return a[find_set(i)];
    }
};


void solve() {
    int n;
    cin >> n;
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    disjoint_set_union dsu(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> dsu.a[i];
    }
    for (int i = 0; i < n; ++i) {
        dsu.check(i, 0);
    }
    for (int i = 0; i < n; ++i) {
        if (dsu.find_set(i) == i) {
            ans = max(ans, abs(dsu.a[i]));
            pq.push({abs(dsu.a[i]), i});
        }
    }
    while (!pq.empty()) {
        auto [ai, i] = pq.top();
        // cerr << i << ": " << ai << endl;
        pq.pop();
        if (i != dsu.find_set(i)) {
            continue;
        }
        i = dsu.find_set(i);
        if (abs(dsu.a[i]) != ai) {
            continue;
        }
        dsu.a[i] = 0;
        dsu.check(i, ai);
        i = dsu.find_set(i);
        if (dsu.a[i] != 0) {
            ans = max(ans, abs(dsu.a[i]));
            pq.push({abs(dsu.a[i]), i});
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}