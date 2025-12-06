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
    int n, x = 0;
    cin >> n;
    xor_basis basis;
    deque<int> ans;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        x ^= k;
        cerr << x << "\n";
        basis.add_vector(x);
    }
    for (int i = 1; i < (1 << 20); ++i) {
        if (basis.check_possible(i)) {
            ans.push_back(i);
        }
    }
    if (basis.sz != n) {
        ans.push_front(0);
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}