#include <bits/stdc++.h>
using namespace std;

void solve() {
    int d, n, sz = 0, k;
    cin >> d >> n;
    vector<int> basis(d);
    while (n--) {
        cin >> k;
        for (int i = 0; i < d; ++i)
            if (k & (1 << i)) {
                if (!basis[i]) {
                    basis[i] = k;
                    ++sz;
                    break;
                }
                k ^= basis[i];
            }
    }
    cout << (1 << (d - sz)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}