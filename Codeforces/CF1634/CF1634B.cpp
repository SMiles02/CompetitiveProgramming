#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, k;
    long long y, s = 0;
    cin >> n >> x >> y;
    while (n--) {
        cin >> k;
        s += k;
    }
    if (((s + x) & 1) == (y & 1))
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}