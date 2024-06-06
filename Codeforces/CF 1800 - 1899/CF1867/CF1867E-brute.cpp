#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int mx = 0;
    for (int n = 1; n <= 2500; ++n) {
        for (int k = 1; k <= n; ++k) {
            if (n <= k * k && k * k <= 2500) {
                mx = max(mx, (n + k - 1) / k);
            }
        }
    }
    cout << mx;
    return 0;
}