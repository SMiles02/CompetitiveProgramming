#include <bits/stdc++.h>
using namespace std;

struct two_sat {
    int n, component_count;
    vector<vector<int>> edges, reverse_edges;
    vector<int> component, component_size;
    two_sat(int n) : n(n), edges(n * 2 + 1), reverse_edges(n * 2 + 1), component(n * 2 + 1), component_size(n * 2 + 1), component_count(0) {}
    void add_edge(int x, bool a, int y, bool b) {
        x += n * a;
        y += n * b;
        edges[x].push_back(y);
        reverse_edges[y].push_back(x);
    }
    void dfs(int c, vector<int>& out_order, vector<bool>& done) {
        done[c] = true;
        for (int i : edges[c])
            if (!done[i])
                dfs(i, out_order, done);
        out_order.push_back(c);
    }
    void dfs_reverse(int c, vector<bool>& done) {
        done[c] = true;
        component[c] = component_count;
        ++component_size[component_count];
        for (int i : reverse_edges[c])
            if (!done[i])
                dfs_reverse(i, done);
    }
    void build_scc() {
        vector<int> out_order;
        vector<bool> done(n * 2 + 1, false), done_reverse(n * 2 + 1, false);
        for (int i = 1; i <= n * 2; ++i)
            if (!done[i])
                dfs(i, out_order, done);
        component_count = 0;
        for (int i = out_order.size() - 1; i >= 0; --i)
            if (!done_reverse[out_order[i]]) {
                ++component_count;
                component_size[component_count] = 0;
                dfs_reverse(out_order[i], done_reverse);
            }
    }
    vector<bool> solve_two_sat() {
        build_scc();
        vector<bool> ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (component[i] == component[i + n]) {
                return ans;
            }
        }
        ans[0] = true;
        vector<vector<int>> to(component_count + 1), comp_members(component_count + 1);
        vector<int> from_cnt(component_count + 1), v;
        vector<bool> done(n + 1);
        for (int i = 1; i <= n * 2; ++i) {
            comp_members[component[i]].push_back(i);
            for (int j : edges[i]) {
                if (component[i] != component[j]) {
                    to[component[j]].push_back(component[i]);
                    ++from_cnt[component[i]];
                }
            }
        }
        for (int i = 1; i <= component_count; ++i) {
            if (from_cnt[i] == 0) {
                v.push_back(i);
            }
        }
        while (!v.empty()) {
            int cur_comp = v.back();
            v.pop_back();
            for (int i : to[cur_comp]) {
                if (--from_cnt[i] == 0) {
                    v.push_back(i);
                }
            }
            bool good = true;
            for (int i : comp_members[cur_comp]) {
                good &= !done[i - n * (i > n)];
            }
            if (good) {
                for (int i : comp_members[cur_comp]) {
                    done[i - n * (i > n)] = true;
                    ans[i - n * (i > n)] = (i > n);
                }
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> m >> n;
    two_sat s(n);
    while (m--) {
        char a, b;
        int x, y;
        cin >> a >> x >> b >> y;
        s.add_edge(x, a != '+', y, b == '+');
        s.add_edge(y, b != '+', x, a == '+');
    }
    vector<bool> ans = s.solve_two_sat();
    if (!ans[0]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) {
            cout << "+ ";
        }
        else {
            cout << "- ";
        }
    }
    return 0;
}