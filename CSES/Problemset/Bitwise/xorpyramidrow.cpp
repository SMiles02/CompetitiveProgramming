#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    k = n - k;
    for (int j = 17; j >= 0; --j) {
        if (k & (1 << j)) {
            n -= (1 << j);
            for (int i = 0; i < n; ++i) {
                a[i] ^= a[i + (1 << j)];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}