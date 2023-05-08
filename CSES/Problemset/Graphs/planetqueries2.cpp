#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, L = 19;
int up[L][N], to[N], cycle_head[N], cycle_order[N], cycle_size[N];
bitset<N> dn;

void dfs(int c, int ord) {
    dn[c] = 1;
    cycle_order[c] = ord;
    if (!dn[up[0][c]]) {
        cycle_head[up[0][c]] = cycle_head[c];
        dfs(up[0][c], ord + 1);
        cycle_size[c] = cycle_size[up[0][c]];
    }
    else
        cycle_size[c] = ord + 1;
}

int dist_to_cycle(int x) {
    int ans = 0;
    for (int i = L - 1; i >= 0; --i)
        if (cycle_head[up[i][x]] == 0) {
            ans += 1 << i;
        x = up[i][x];
    }
    return ans + (cycle_head[x] == 0);
}

int lift(int x, int d) {
    for (int i = 0; i < L; ++i)
        if (d & (1 << i))
            x = up[i][x];
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> up[0][i];
        ++to[up[0][i]];
    }
    for (int j = 1; j < L; ++j)
        for (int i = 1; i <= n; ++i)
            up[j][i] = up[j - 1][up[j - 1][i]];
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        if (to[i] == 0)
            v.push_back(i);
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        dn[x] = 1;
        if (--to[up[0][x]] == 0)
            v.push_back(up[0][x]);
    }
    for (int i = 1; i <= n; ++i)
        if (!dn[i]) {
            cycle_head[i] = i;
            dfs(i, 0);
        }
    while (q--) {
        int x, y;
        cin >> x >> y;
        bool cyc_x = (cycle_head[x] != 0), cyc_y = (cycle_head[y] != 0);
        if (cyc_x && cyc_y) {
            if (cycle_head[x] == cycle_head[y])
                cout << (cycle_order[y] - cycle_order[x] + cycle_size[x]) % cycle_size[x] << "\n";
            else
                cout << "-1\n";
        }
        else if (cyc_x && !cyc_y) {
            cout << "-1\n";
        }
        else if (cyc_y) {
            if (cycle_head[up[L - 1][x]] == cycle_head[y]) {
                int ans = 0;
                for (int i = L - 2; i >= 0; --i)
                    if (cycle_head[up[i][x]] == 0) {
                        ans += 1 << i;
                        x = up[i][x];
                    }
                ++ans;
                x = up[0][x];
                ans += (cycle_order[y] - cycle_order[x] + cycle_size[x]) % cycle_size[x];
                cout << ans << "\n";
            }
            else
                cout << "-1\n";
        }
        else {
            if (cycle_head[up[L - 1][x]] == cycle_head[up[L - 1][y]] && dist_to_cycle(x) >= dist_to_cycle(y) && lift(x, dist_to_cycle(x) - dist_to_cycle(y)) == y)
                cout << dist_to_cycle(x) - dist_to_cycle(y) << "\n";
            else
                cout << "-1\n";
        }
    }
    return 0;
}