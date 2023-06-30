#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    int n;
    vector<long long> bit;
    fenwick_tree(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) {
        for (int i = x; i <= n; i += i & -i) {
            bit[i] += d;
        }
    }
    long long query(int x) {
        long long sum = 0;
        for (int i = x; i; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }
    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int midpoint(int l, int r) {
    return l + (r - l) / 2;
}

const int N = 3e5 + 2, L = 19;
int target[N], ans[N];
vector<int> has_sectors[N];
array<int, 3> meteors[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int owner;
        cin >> owner;
        has_sectors[owner].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> target[i];
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> meteors[i][j];
        }
    }
    vector<vector<array<int, 3>>> pbs(k + 1);
    for (int i = 1; i <= n; ++i) {
        pbs[midpoint(0, k)].push_back({0, k, i});
        ans[i] = k;
    }
    for (int iter = 0; iter < L; ++iter) {
        fenwick_tree bit(m + 1);
        vector<vector<array<int, 3>>> new_pbs(k + 1);
        for (int i = 0; i < k; ++i) {
            auto &[l, r, x] = meteors[i];
            bit.update(l, x);
            bit.update(r + 1, -x);
            if (l > r) {
                bit.update(1, x);
            }
            for (auto &[lb, rb, id] : pbs[i]) {
                long long sum = 0;
                for (auto sector : has_sectors[id]) {
                    sum += bit.query(sector);
                }
                int newl, newr;
                if (sum < target[id]) {
                    newl = i + 1;
                    newr = rb;
                }
                else {
                    ans[id] = min(ans[id], i);
                    newl = lb;
                    newr = i - 1;
                }
                if (newl <= newr) {
                    new_pbs[midpoint(newl, newr)].push_back({newl, newr, id});
                }
            }
        }
        swap(pbs, new_pbs);
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == k) {
            cout << "NIE\n";
        }
        else {
            cout << ans[i] + 1 << "\n";
        }
    }
    return 0;
}