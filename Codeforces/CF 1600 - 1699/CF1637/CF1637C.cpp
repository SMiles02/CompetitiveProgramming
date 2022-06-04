#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, o = 0;
    long long s = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i + 1 < n; ++i) {
        o += a[i] & 1;
        s += a[i];
    }
    if (s == n - 2 || (s % 2 && n == 3))
        cout << "-1\n";
    else
        cout << (s + o) / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}