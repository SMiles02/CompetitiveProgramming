const long long INF = 1e18;

struct li_chao_tree {
    struct node {
        long long a = 0, b = INF;
        node *l, *r;
    };
    int n;
    node *root;
    deque<node> buffer;
    node *newnode() {
        buffer.emplace_back();
        return &buffer.back();
    }
    li_chao_tree(int n) : n(n) {
        root = newnode();
    }
    int get_midpoint(int l, int r) {
        return l + (r - l) / 2;
    }
    long long f(long long a, long long b, int x) {
        return a * x + b;
    }
    void update(node *&v, int l, int r, long long a, long long b) {
        if (!v) {
            v = newnode();
            v->a = a;
            v->b = b;
        }
        int m = get_midpoint(l, r);
        if (f(a, b, m) < f(v->a, v-> b, m)) {
            swap(a, v->a);
            swap(b, v->b);
        }
        if (l == r)
            return;
        if (f(a, b, l) < f(v->a, v->b, l))
            update(v->l, l, m, a, b);
        else if (f(a, b, l) < f(v->a, v->b, r))
            update(v->r, m + 1, r, a, b);
    }
    void add_line(long long a, long long b) {
        update(root, 0, n, a, b);
    }
    long long query(node *v, int l, int r, int x) {
        if (!v)
            return INF;
        if (l == r)
            return f(v->a, v->b, x);
        int m = get_midpoint(l, r);
        if (x <= m)
            return min(f(v->a, v->b, x), query(v->l, l, m, x));
        return min(f(v->a, v->b, x), query(v->r, m + 1, r, x));
    }
    long long query(int x) {
        return query(root, 0, n, x);
    }
};