#include <bits/stdc++.h>
using namespace std;

struct xor_basis {
    int sz;
    vector<int> basis;
    xor_basis() : sz(0) {}
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    xor_basis basis;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        basis.add_vector(k);
    }
    cout << (1 << basis.sz);
    return 0;
}