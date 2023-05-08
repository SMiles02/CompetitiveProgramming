#include <bits/stdc++.h>
using namespace std;

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
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
int reg_val() { return -1; }

const int N = 1e5 + 1;
int n, a[N], b[N * 2], tin[N], tout[N], t = 1, ans[N];
vector<int> e[N];

void dfs(int c, int p) {
    tin[c] = t++;
    b[tin[c]] = b[tin[c] + n] = a[c];
    for (int i : e[c])
        if (i != p)
            dfs(i, c);
    tout[c] = t - 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y, cur = 0;
    cin >> n;
    vector<array<int, 2>> ed(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        ed[i] = {x, y};
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dfs(1, 0);
    segtree<int, op, reg_val> seg(n * 2 + 1);
    vector<vector<array<int, 2>>> queries(n * 2 + 1);
    vector<int> ans(n - 1);
    map<int, int> m;
    for (int i = 0; i < n - 1; ++i) {
        if (tin[ed[i][1]] > tin[ed[i][0]])
            swap(ed[i][0], ed[i][1]);
        queries[tout[ed[i][0]]].push_back({tin[ed[i][0]], i});
        queries[tin[ed[i][0]] + n - 1].push_back({tout[ed[i][0]] + 1, i});
    }
    for (int i = 1; i <= n * 2; ++i) {
        if (m[b[i]])
            seg.set(m[b[i]], b[i]);
        m[b[i]] = i;
        for (auto j : queries[i])
            ans[j[1]] = max(ans[j[1]], seg.prod(j[0], i + 1));
    }
    for (int i : ans)
        cout << i << "\n";
    return 0;
}