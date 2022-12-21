#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n, k, g = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        g = gcd(g, k);
    }
    cout << k / g << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}