#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, int b) {
    if (k * 2 - b <= n) {
        return k * 2 - b;
    }
    return solve((n + 1 - b) / 2, k - (n + b) / 2, (n + b) % 2) * 2 - 1 + b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q, n, k;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        cout << solve(n, k, 0) << "\n";
    }
    return 0;
}