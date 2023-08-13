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

using S = array<int, 2>;

// basic operation
S op(S a, S b) { return max(a, b); }

// op(anything, e()) = anything
S e() { return {-1, -1}; }

// currently query max
// remember: range l, r means [l, r)

// Constructor:
// (1) segment_tree<S, op, e> seg(int n)
// (2) segment_tree<S, op, e> seg(vector<S> v)

// Functions:
// seg.set(int p, S x) => a[p] := x
// seg.get(int p) => a[p]
// seg.prod(int l, int r) => op(a[l], ..., a[r - 1])
// seg.all_prod() => op(a[0], ..., a[n - 1])
// seg.min_left<cnd>(int r) => minimum l such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true
// seg.max_right<cnd>(int r) => maximum r such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    int query(int x) {
        int rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};

const int N = 1e6 + 1;
int n, a[N], p[N];
ll ans;
array<int, 2> q[N];
segment_tree<S, op, e> seg(N);

void solve(int l, int r) {
    if (l > r) {
        return;
    }
    array<int, 2> cur = seg.prod(l, r + 1);
    solve(l, cur[1] - 1);
    solve(cur[1] + 1, r);
    if (cur[1] - l < r - cur[1]) {
        int lp = cur[1], rp = cur[1], mn = cur[0];
        while (l <= lp - 1) {
            --lp;
            mn = min(mn, a[lp]);
            while (rp + 1 <= r && mn < a[rp + 1]) {
                ++rp;
            }
            ans += rp - cur[1] + 1;
        }
    }
    else {
        int lp = cur[1], rp = cur[1], mn = cur[0];
        while (rp + 1 <= r) {
            mn = min(mn, a[rp]);
            while (l <= lp - 1)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    bool is_sorted = true;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        is_sorted &= a[i] == i;
        p[a[i]] = i;
        seg.set(i, {a[i], i});
    }
    if (is_sorted) {
        cout << (1LL * n * (n - 1)) / 2 << "\n";
        return 0;
    }
    solve(1, n);
    // BIT bit(n);
    // for (int i = 1; i <= n; ++i) {
    //     bit.update(p[i], 1);
    //     ans += bit.query(q[i][0], q[i][1]);
    // }
    cout << ans;
    return 0;
}