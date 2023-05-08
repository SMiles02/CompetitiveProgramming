struct tree {
    int N, L, timer = 0;
    vector<int> tin, tout, height;
    vector<vector<int>> up, e;
    tree(int n) : N(n), L((int)log2(n + 1) + 1), e(n + 1), tin(n + 1), tout(n + 1), height(n + 1), up((int)log2(n + 1) + 1, vector<int>(n + 1)) {}
    void add_directed_edge(int x, int y) {
        e[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        e[x].push_back(y);
        e[y].push_back(x);
    }
    void build_lca(int c, int p) {
        up[0][c] = p;
        height[c] = height[p] + 1;
        for (int i = 1; i < L; ++i)
            up[i][c] = up[i - 1][up[i - 1][c]];
        tin[c] = ++timer;
        for (int i : e[c])
            if (i != p)
                build_lca(i, c);
        tout[c] = timer;
    }
    void build_queries(int root = 1) {
        build_lca(root, 0);
        tout[0] = ++timer;
    }
    bool is_ancestor(int x, int y)  {
        return (tin[x] <= tin[y] && tout[y] <= tout[x]);
    }
    int query_kth_ancestor(int x, int k) {
        for (int i = 0; i < L; ++i)
            if (k & (1 << i))
                x = up[i][x];
        return x;
    }
    int lca(int x, int y) {
        if (is_ancestor(x, y))
            return x;
        if (is_ancestor(y, x))
            return y;
        for (int i = L - 1; i >= 0; --i)
            if (!is_ancestor(up[i][x], y))
                x = up[i][x];
        return up[0][x];
    }
    int query_distance(int x, int y) {
        return height[x] + height[y] - height[lca(x, y)] * 2;
    }
};

// Constructor:
// Tree tree(n); where n nodes from 1 to n

// Adding edges:
// add_undirected_edge(x, y) => adds an edge between x and y
// add_directed_edge(x, y) => adds an edge from x (parent) to y (child)

// When all edges have been added,
// build_queries(int root = 1)

// Afterwards:
// is_ancestor(x, y) => bool: checks if x is an ancestor of y
// query_kth_ancestor(int x, int k) => int: returns the k-th ancestor of x. Will return 0 if this ancestor doesn't exist
// lca(x, y) => int: returns the lowest common ancestor of x and y
// query_distance(x, y) => returns the distance between x and y on the tree