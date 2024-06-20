struct xor_basis {
    int n, sz;
    vector<int> basis;
    xor_basis(int n) : n(n), sz(0) {}
    void add_vector(int mask) {
        for (auto &i : basis) {
            mask = min(mask, mask ^ i);
        }
        if (mask) {
            basis.push_back(mask);
            ++sz;
        }
    }
    bool check_possible(int mask) {
        for (auto &i : basis) {
            mask = min(mask, mask ^ i);
        }
        return mask == 0;
    }
};