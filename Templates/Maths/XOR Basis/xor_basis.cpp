struct xor_basis {
    int n, sz;
    vector<int> basis;
    xor_basis(int n) : n(n), sz(0), basis(n) {}
    void add_vector(int mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }
            if (!basis[i]) {
                basis[i] = mask;
                ++sz;
                return;
            }
            mask ^= basis[i];
        }
    }
    bool check_possible(int mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }
            if (!basis[i]) {
                return false;
            }
            mask ^= basis[i];
        }
        return true;
    }
};