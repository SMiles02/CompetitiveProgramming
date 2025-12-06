#include <bits/stdc++.h>
using namespace std;

struct xor_basis {
    int n;
    vector<int> basis;
    xor_basis(int n) : n(n), basis(n) {}
    void add_vector(int mask) {
        for (int i = n - 1; i >= 0; --i) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }
            if (!basis[i]) {
                basis[i] = mask;
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
    int find_max() {
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (!basis[i] || (ans & (1 << i))) {
                continue;
            }
            ans ^= basis[i];
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0;
    cin >> n;
    xor_basis basis(30);
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        basis.add_vector(k);
    }
    cout << basis.find_max();
    return 0;
}