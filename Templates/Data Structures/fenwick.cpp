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
