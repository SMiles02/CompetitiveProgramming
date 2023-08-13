// Note: this isn't finished / tested, use at your own risk

template <class S, S (*op)(S, S), S (*e)()> struct sparse_table {
    int n, lg;
    vector<vector<S>> st;
    sparse_table(int n) : n(n), lg((int)log2(n) + 2), st((int)log2(n) + 2, vector<int>(n, e())) {}
    void set(int i, S x) {
        st[0][i] = x;
    }
    void build() {
        for (int j = 1; j < lg; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << j)]);
            }
        }
    }
    S query(int l, int r) {
        int cur_lg = (int)log2(r - l + 1);
        return op(st[cur_lg][l], st[cur_lg][r - (1 << cur_lg) + 1]);
    }
};

// basic operation
int op(int a, int b) { return max(a, b); }

// op(anything, e()) = anything
int e() { return -1; }

// currently query max
// note: range l, r means [l, r]

// Constructor:
// (1) sparse_table<S, op, e> seg(int n)

// To-do: add function guide here.