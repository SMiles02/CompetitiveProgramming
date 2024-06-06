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
 
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
 
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
 
    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
 
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
 
        l += size;
        r += size;
 
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
 
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
 
        return op(sml, smr);
    }
 
    S all_prod() { return d[1]; }
 
    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
 
        l += size;
        r += size;
 
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
 
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
 
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
 
    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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
 
    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;
 
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

struct S {
    long long val;
    int id, node;
};

using F = long long;
S op(S l, S r) {
    if (l.val > r.val) {
        return r;
    }
    if (l.val < r.val) {
        return l;
    }
    if (l.id > r.id) {
        return r;
    }
    return l;
}

const S INF = {(long long) 1e18, (long long) 1e9, (long long) 1e9};
S e() { return INF; }
S mapping(F l, S r) { return {r.val + l, r.id, r.node}; }
F composition(F l, F r) { return l + r; }
F id() { return 0; }

struct heavy_light_decomposition {
    int n;
    vector<vector<int>> edges;
    vector<int> par, heavy, height, pos, head, tout;
    heavy_light_decomposition(int n) : n(n), edges(n + 1), par(n + 1),  heavy(n + 1), height(n + 1), pos(n + 1), head(n + 1), tout(n + 1) { }
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
        tout[c] = timer;
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
    int n, m, q;
    cin >> n >> m >> q;
    heavy_light_decomposition hld(n);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    vector<deque<int>> next_girl(n + 1);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        hld.add_edge(x, y);
    }
    hld.build();
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        next_girl[x].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (!next_girl[i].empty()) {
            seg.set(hld.get_position(i), {next_girl[i][0], next_girl[i][0], i});
            next_girl[i].pop_front();
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v, k;
            cin >> u >> v >> k;
            vector<array<int, 2>> queries = hld.path_queries(u, v);
            vector<int> ans;
            while (k--) {
                S cur = INF;
                for (auto [l, r] : queries) {
                    cur = op(cur, seg.prod(l, r + 1));
                }
                if (cur.val == 1e18) {
                    break;
                }
                auto [val, id, node] = cur;
                ans.push_back(id);
                if (next_girl[node].empty()) {
                    seg.set(hld.get_position(node), INF);
                }
                else {
                    seg.set(hld.get_position(node), {next_girl[node].front() + val - id, next_girl[node].front(), node});
                    next_girl[node].pop_front();
                }
            }
            cout << ans.size() << " ";
            for (int i : ans) {
                cout << i << " ";
            }
            cout << "\n";
        }
        else {
            int v, k;
            cin >> v >> k;
            seg.apply(hld.get_position(v), hld.tout[v], k);
        }
    }
    return 0;
}