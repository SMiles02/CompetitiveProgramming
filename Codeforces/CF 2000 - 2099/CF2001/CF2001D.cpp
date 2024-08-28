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

const int INF = 1e9;
using S = array<array<int, 2>, 2>;

S arf(int a, int b, int c, int d) {
    S tmp;
    tmp[0][0] = a;
    tmp[0][1] = b;
    tmp[1][0] = c;
    tmp[1][1] = d;
    return tmp;
}

// basic operation
S op(S a, S b) {
    S tmp = {min(a[0], b[0]), max(a[1], b[1])};
    if (a[1][0] == b[1][0]) {
        tmp[1][1] = min(a[1][1], b[1][1]);
    }
    return tmp;
}

S e_arr;

// op(anything, e()) = anything
S e() {
    return e_arr;
}

void solve() {
    int n, cnt = 0, done_cnt = 0, id = 0;
    cin >> n;
    vector<int> a(n), buffer = {n};
    vector<bool> d(n + 1), dn(n + 1);
    segment_tree<S, op, e> seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seg.set(i, arf(a[i], i, a[i], i));
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!d[a[i]]) {
            d[a[i]] = true;
            ++cnt;
            buffer.push_back(i);
        }
    }
    vector<int> ans;
    while (done_cnt < cnt) {
        while (dn[a[buffer.back()]]) {
            buffer.pop_back();
        }
        int i = buffer.back();
        S cur = seg.prod(id, i + 1);
        // cout << "searching [" << id << ", " << i + 1 << "]\n";
        if (done_cnt & 1) {
            if (!dn[cur[0][0]]) {
                ++done_cnt;
                dn[cur[0][0]] = true;
                ans.push_back(cur[0][0]);
                id = cur[0][1] + 1;
            }
            seg.set(cur[0][1], e());
        }
        else {
            if (!dn[cur[1][0]]) {
                ++done_cnt;
                dn[cur[1][0]] = true;
                ans.push_back(cur[1][0]);
                id = cur[1][1] + 1;
            }
            seg.set(cur[1][1], e());
        }
    }
    cout << done_cnt << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    e_arr = arf(INF, 0, -INF, 0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}