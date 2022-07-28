#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
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

const int INF = 1e9;

// basic operation
int min_op(int a, int b) { return min(a, b); }
int max_op(int a, int b) { return max(a, b); }

// op(anything, e()) = anything
int min_e() { return INF; }
int max_e() { return -1; }

// currently query max
// remember: range l, r means [l, r)

// Constructor:
// (1) segtree<S, op, e> seg(int n)
// (2) segtree<S, op, e> seg(vector<S> v)

// Functions:
// seg.set(int p, S x) => a[p] := x
// seg.get(int p) => a[p]
// seg.prod(int l, int r) => op(a[l], ..., a[r - 1])
// seg.all_prod() => op(a[0], ..., a[n - 1])
// seg.min_left<cnd>(int r) => minimum l such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true
// seg.max_right<cnd>(int r) => maximum r such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true

const int N = 3e5;
bitset<N> dn;

void solve() {
    int n, x, y, z, k, d;
    cin >> n;
    vector<int> v(n), p(n), dt(n);
    for (int i = 0; i < n; ++i) {
        dn[i] = 0;
        cin >> v[i];
        --v[i];
        p[v[i]] = i;
    }
    segtree<int, min_op, min_e> seg_min(v);
    segtree<int, max_op, max_e> seg_max(v);
    set<int> sf_min, sf_max;
    set<int, greater<int>> pf_min, pf_max;
    queue<array<int, 2>> q;
    q.push({0, 0});
    dn[0] = 1;
    pf_min.insert(0);
    pf_max.insert(0);
    pf_min.insert(-1);
    pf_max.insert(-1);
    sf_min.insert(n);
    sf_max.insert(n);
    while (!q.empty()) {
        x = q.front()[0];
        y = q.front()[1];
        q.pop();
        dt[x] = y;
        z = (*pf_min.upper_bound(x)) + 1;
        while (z < x) {
            k = seg_min.prod(z, x + 1);
            d = p[k];
            if (d == x)
                break;
            if (seg_max.prod(d, x + 1) != v[x])
                pf_min.insert(d - 1);
            else {
                pf_min.insert(d);
                if (!dn[d]) {
                    dn[d] = 1;
                    q.push({d, y + 1});
                }
            }
            z = d + 1;
        }
        z = (*pf_max.upper_bound(x)) + 1;
        while (z < x) {
            k = seg_max.prod(z, x + 1);
            d = p[k];
            if (d == x)
                break;
            if (seg_min.prod(d, x + 1) != v[x])
                pf_max.insert(d - 1);
            else {
                pf_max.insert(d);
                if (!dn[d]) {
                    dn[d] = 1;
                    q.push({d, y + 1});
                }
            }
            z = d + 1;
        }
        z = (*sf_min.upper_bound(x)) - 1;
        while (x < z) {
            k = seg_min.prod(x, z + 1);
            d = p[k];
            if (d == x)
                break;
            if (seg_max.prod(x, d + 1) != v[x])
                sf_min.insert(d + 1);
            else {
                sf_min.insert(d);
                if (!dn[d]) {
                    dn[d] = 1;
                    q.push({d, y + 1});
                }
            }
            z = d - 1;
        }
        z = (*sf_max.upper_bound(x)) - 1;
        while (x < z) {
            k = seg_max.prod(x, z + 1);
            d = p[k];
            if (d == x)
                break;
            if (seg_min.prod(x, d + 1) != v[x])
                sf_max.insert(d + 1);
            else {
                sf_max.insert(d);
                if (!dn[d]) {
                    dn[d] = 1;
                    q.push({d, y + 1});
                }
            }
            z = d - 1;
        }

    }
    cout << dt[n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}