#include <bits/stdc++.h>
using namespace std;

namespace internal {
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}

template <class S, S (*op)(S, S), S (*e)()> struct segment_tree {
  public:
    segment_tree() : segment_tree(0) {}
    explicit segment_tree(int n) : segment_tree(std::vector<S>(n, e())) {}
    explicit segment_tree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

struct heavy_light_decomposition {
    int n;
    vector<vector<int>> edges;
    vector<int> par, heavy, height, pos, head;
    heavy_light_decomposition(int n) : n(n), edges(n + 1), par(n + 1),  heavy(n + 1), height(n + 1), pos(n + 1), head(n + 1) { }
    void add_edge(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    void heavy_dfs(int c, vector<int>& sub) {
        heavy[c] = -1;
        sub[c] = 1;
        int max_size = 0;
        for (int i : edges[c]) {
            if (i != par[c]) {
                par[i] = c;
                height[i] = height[c] + 1;
                heavy_dfs(i, sub);
                sub[c] += sub[i];
                if (sub[i] > max_size) {
                    heavy[c] = i;
                    max_size = sub[i];
                }
            }
        }
    }
    void decompose(int c, int h, int& timer) {
        pos[c] = timer++;
        head[c] = h;
        if (heavy[c] != -1) {
            decompose(heavy[c], h, timer);
        }
        for (int i : edges[c]) {
            if (i != par[c] && i != heavy[c]) {
                decompose(i, i, timer);
            }
        }
    }
    void build() {
        int timer = 0;
        vector<int> sub(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (sub[i] == 0) {
                par[i] = 0;
                height[i] = 0;
                heavy_dfs(i, sub);
                decompose(i, i, timer);
            }
        }
    }
    int get_position(int x) {
        return pos[x];
    }
    vector<array<int, 2>> path_queries(int x, int y) {
        vector<array<int, 2>> queries;
        while (head[x] != head[y]) {
            if (height[head[x]] > height[head[y]]) {
                swap(x, y);
            }
            queries.push_back({pos[head[y]], pos[y]});
            y = par[head[y]];
        }
        if (height[x] > height[y]) {
            swap(x, y);
        }
        queries.push_back({pos[x], pos[y]});
        return queries;
    } 
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    heavy_light_decomposition hld(n);
    segment_tree<int, op, e> seg(n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        hld.add_edge(x, y);
    }
    hld.build();
    for (int i = 1; i <= n; ++i) {
        seg.set(hld.get_position(i), v[i]);
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            seg.set(hld.get_position(x), y);
        }
        else {
            vector<array<int, 2>> queries = hld.path_queries(x, y);
            int cur_ans = 0;
            for (auto [l, r] : queries) {
                cur_ans = max(cur_ans, seg.prod(l, r + 1));
            }
            cout << cur_ans << " ";
        }
    }
    return 0;
}