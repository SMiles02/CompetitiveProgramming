#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF = 1e9;

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
 
// values
using S = int;

// lazy values
using F = int;

// basic operation 
S op(S l, S r) { return min(l, r); }

// op(anything, e()) = anything
S e() { return INF; }

// how a lazy update affects a value
S mapping(F l, S r) { return min(l, r); }
 
// how lazy update l affects existing lazy r
F composition(F l, F r) { return min(l, r); }

// base lazy
F id() { return INF; }

// currently update multiply / add, query sum
// remember: range l, r means [l, r)

// Constructor:
// (1) lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);
// (2) lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v);

// Functions:
// seg.set(int p, S x) => a[p] := x
// seg.get(int p) => a[p]
// seg.prod(int l, int r) => op(a[l], ..., a[r - 1])
// seg.all_prod() => op(a[0], ..., a[n - 1])
// seg.apply(int p, F f) => a[p] = f(a[p])
// seg.apply(int l, int r, F f) => a[i] = f(a[i]) for all i = l ... r - 1
// seg.min_left<cnd>(int r) => minimum l such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true
// seg.max_right<cnd>(int r) => maximum r such that g(op(a[l], ..., a[r - 1])) = true
// => Constraints: g(e()) = true

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;

int getRand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int sub(int a, int b) { return add(a, MOD - b); }

struct Hash
{
    // All 1-indexed
    int baseCnt, maxLen, cur = 0;
    vector<vector<int>> bases, inverse;
    vector<vector<vector<int>>> hashVal;
    Hash(int baseCnt, int maxLen) : baseCnt(baseCnt), maxLen(maxLen), bases(baseCnt, vector<int>(maxLen + 1)), inverse(baseCnt, vector<int>(maxLen + 1)) {
        for (int i = 0; i < baseCnt; ++i) {
            bases[i][0] = 1;
            bases[i][1] = getRand(10000, 200000);
            inverse[i][0] = 1;
            inverse[i][1] = binpow(bases[i][1], MOD - 2);
            for (int j = 2; j <= maxLen; ++j) {
                bases[i][j] = mul(bases[i][j - 1], bases[i][1]);
                inverse[i][j] = mul(inverse[i][j - 1], inverse[i][1]);
            }
        }
        hashVal.push_back({{}});
    }
    void addString(string& s) {
        int n = s.size();
        ++cur;
        hashVal.push_back(vector<vector<int>>(baseCnt, vector<int>(n + 1)));
        for (int i = 0; i < baseCnt; ++i)
            for (int j = 0; j < n; ++j)
                hashVal[cur][i][j + 1] = add(hashVal[cur][i][j], mul(bases[i][j], s[j] - 'a' + 1));
    }
    int calcVal(int id, int base, int l, int r) {
        return mul(sub(hashVal[id][base][r], hashVal[id][base][l - 1]), inverse[base][l - 1]);
    }
    bool isEqual(int id1, int l1, int r1, int id2, int l2, int r2) {
        for (int i = 0; i < baseCnt; ++i)
            if (calcVal(id1, i, l1, r1) != calcVal(id2, i, l2, r2))
                return false;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, l, r, mid;
    string s, t;
    cin >> s;
    cin >> t;
    n = s.size();
    m = t.size();
    Hash hash(3, 5e5);
    hash.addString(s);
    hash.addString(t);
    s = "?" + s;
    t = "?" + t;
    vector<int> dp(m + 1, INF);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(m + 1);
    seg.set(0, 0);
    dp[0] = 0;
    for (int i = 1; i <= m; ++i)
        seg.set(i, INF);
    for (int i = 1; i <= m; ++i) {
        if (t[i] == s[1]) {
            l = 1;
            r = min(m - i + 1, n);
            while (l < r) {
                mid = l + (r - l) / 2 + 1;
                if (hash.isEqual(1, 1, mid, 2, i, i + mid - 1))
                    l = mid;
                else
                    r = mid - 1;
            }
            seg.apply(i, i + l, dp[i - 1] + 1);
        }
        dp[i] = seg.get(i);
    }
    if (dp[m] == INF)
        dp[m] = -1;
    cout << dp[m];
    return 0;
}