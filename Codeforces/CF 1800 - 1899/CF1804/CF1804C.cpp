#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, p;
    cin >> n >> x >> p;
    for (int i = 1; i <= min(n * 2, p); ++i) {
        x = (x + i) % n;
        if (x == 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}