#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    int k = __builtin_popcountll(n);
    if (k == 1) {
        cout << "1\n" << n << "\n";
        return;
    }
    cout << k + 1 << "\n";
    for (int i = 0; i <= k; ++i) {
        long long ans = 0;
        int cnt = 0;
        for (int j = 59; j >= 0; --j) {
            if (n & (1LL << j)) {
                if ((cnt++) != i) {
                    ans ^= 1LL << j;
                }
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}