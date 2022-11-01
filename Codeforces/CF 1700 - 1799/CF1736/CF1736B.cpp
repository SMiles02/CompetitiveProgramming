#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    int a[n], b[n + 1];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    b[0] = a[0];
    for (int i = 0; i + 1 < n; ++i)
        b[i + 1] = lcm(a[i], a[i + 1]);
    b[n] = a[n - 1];
    for (int i = 0; i < n; ++i)
        if (a[i] != gcd(b[i], b[i + 1])) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}