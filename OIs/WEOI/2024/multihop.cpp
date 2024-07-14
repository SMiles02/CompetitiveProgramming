#include <vector>
#include <array>
using namespace std;

struct min_cost {
    array<array<long long, 2>, 2> mc;
    // prefix/suffix closed/open
    void init() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                mc[i][j] = 1e18;
            }
        }
    }
};

const int N = 1e5, L = 17;
int p[N], h[N], a[N], b[N], c, lift[L][N];
vector<int> e[N];
min_cost dp_up[L][N], dp_down[L][N];

min_cost merge(min_cost first, min_cost second) {
    min_cost ans;
    ans.init();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                ans.mc[i][k] = min(ans.mc[i][k], first.mc[i][j] + second.mc[j][k]);
            }
        }
    }
    return ans;
}

void dfs(int cur) {
    for (int i = 1; (1 << i) <= h[cur]; ++i) {
        lift[i][cur] = lift[i - 1][lift[i - 1][cur]];
        dp_up[i][cur] = merge(dp_up[i - 1][cur], dp_up[i - 1][lift[i - 1][cur]]);
        dp_down[i][cur] = merge(dp_down[i - 1][lift[i - 1][cur]], dp_down[i - 1][cur]);
    }
    for (int i : e[cur]) {
        if (i == p[cur]) {
            continue;
        }
        p[i] = cur;
        h[i] = h[cur] + 1;
        lift[0][i] = cur;
        dp_up[0][i].mc[0][0] = min(a[i], b[i] + c);
        dp_up[0][i].mc[0][1] = min(a[i] + b[cur], b[i] + c);
        dp_up[0][i].mc[1][0] = min(c, a[i]);
        dp_up[0][i].mc[1][1] = min(c, a[i] + b[cur]);
        dp_down[0][i].mc[0][0] = min(a[cur], b[cur] + c);
        dp_down[0][i].mc[0][1] = min(a[cur] + b[i], b[cur] + c);
        dp_down[0][i].mc[1][0] = min(c, a[cur]);
        dp_down[0][i].mc[1][1] = min(c, a[cur] + b[i]);
        dfs(i);
    }
}

void init(int n, int C, vector<int> A, vector<int> B, vector<int> u, vector<int> v) {
    for (int i = 0; i < n; ++i) {
        a[i] = A[i];
        b[i] = B[i];
    }
    c = C;
    for (int i = 0; i < n - 1; ++i) {
        e[u[i]].push_back(v[i]);
        e[v[i]].push_back(u[i]);
    }
    dfs(0);
}

int lca(int x, int y) {
    if (h[x] < h[y]) {
        swap(x, y);
    }
    for (int i = 0; i < L; ++i) {
        if ((h[x] - h[y]) & (1 << i)) {
            x = lift[i][x];
        }
    }
    if (x == y) { return x; }
    for (int i = L - 1; i >= 0; --i) {
        if (lift[i][x] != lift[i][y]) {
            x = lift[i][x];
            y = lift[i][y];
        }
    }
    return lift[0][x];
}

long long query(int x, int y) {
    int z = lca(x, y);
    min_cost cur_ans;
    cur_ans.init();
    cur_ans.mc[0][0] = 0;
    vector<array<int, 2>> v;
    for (int i = 0; i < L; ++i) {
        if ((h[x] - h[z]) & (1 << i)) {
            cur_ans = merge(cur_ans, dp_up[i][x]);
            x = lift[i][x];
        }
        if ((h[y] - h[z]) & (1 << i)) {
            v.push_back({y, i});
            y = lift[i][y];
        }
    }
    while (!v.empty()) {
        cur_ans = merge(cur_ans, dp_down[v.back()[1]][v.back()[0]]);
        v.pop_back();
    }
    return cur_ans.mc[0][0];
}
