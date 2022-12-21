#include <bits/stdc++.h>
using namespace std;

struct BinaryLifting {
    int N, L;
    vector<vector<int>> up, e;
    BinaryLifting(int n) : N(n), L((int)log2(n + 1) + 1), e(n + 1), up((int)log2(n + 1) + 1, vector<int>(n + 1)) {}
    void add_directed_edge(int x, int y) {
        e[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        e[x].push_back(y);
        e[y].push_back(x);
    }
    void build_lift(int c, int p) {
        up[0][c] = p;
        for (int i = 1; i < L; ++i)
            up[i][c] = up[i - 1][up[i - 1][c]];
        for (int i : e[c])
            build_lift(i, c);
    }
    void build_lift(int root = 1) {
        build_lift(root, 0);
    }
    int query(int x, int y) {
        for (int i = 0; i < L; ++i)
            if (y & (1 << i))
                x = up[i][x];
        return x;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, p, x, y, ans;
    cin >> n >> q;
    BinaryLifting helper(n);
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        helper.add_directed_edge(p, i);
    }
    helper.build_lift();
    while (q--) {
        cin >> x >> y;
        ans = helper.query(x, y);
        if (ans == 0)
            ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
