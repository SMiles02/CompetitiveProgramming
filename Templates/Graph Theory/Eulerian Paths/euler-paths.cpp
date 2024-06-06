struct euler_path {
    int n, edge_count;
    vector<vector<array<int, 2>>> edges;
    euler_path(int n) : n(n), edge_count(0), edges(n + 1) {}
    void add_edge(int x, int y) {
        edges[x].push_back({y, edge_count});
        edges[y].push_back({x, edge_count++});
    }
    void cycle(deque<int>& d) {
        d.push_front(d.back());
        d.pop_back();
    }
    deque<int> find_path(int src = 1) {
        int not_done = 0;
        deque<int> d = {-1, src};
        vector<int> s(n + 1);
        vector<bool> done_edge(edge_count);
        for (int i = 0; i <= n; ++i) {
            not_done += !edges[i].empty();
        }
        while (not_done > 0) {
            int x = d.back();
            if (x == -1) {
                cycle(d);
            }
            while (s[x] < edges[x].size() && done_edge[edges[x][s[x]][1]]) {
                if (++s[x] == edges[x].size()) {
                    --not_done;
                }
            }
            if (s[x] == edges[x].size()) {
                cycle(d);
            }
            else {
                done_edge[edges[x][s[x]][1]] = true;
                d.push_back(edges[x][s[x]][0]);
            }
        }
        while (d[0] != -1) {
            cycle(d);
        }
        d.pop_front();
        return d;
    }
};