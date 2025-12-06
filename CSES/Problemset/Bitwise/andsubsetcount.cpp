#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> f(1 << 3);
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        ++f[k];
    }
    for (int i = 0; i < 3; ++i) {
        for (int mask = 0; mask < (1 << 3); ++mask) {
            if (mask & (1 << i)) {
                f[mask ^ (1 << i)] += f[mask];
            }
        }
    }
    for (int i = 0; i < (1 << 3); ++i) {
        cout << i << ": " << f[i] << "\n";
    }
    return 0;
}