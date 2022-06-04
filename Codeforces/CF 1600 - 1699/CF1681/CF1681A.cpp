#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0, y = 0, k;
    cin >> n;
    while (n--) {
        cin >> k;
        x = max(x, k);
    }
    cin >> n;
    while (n--) {
        cin >> k;
        y = max(y, k);
    }
    if (x >= y)
        cout << "Alice\n";
    else
        cout << "Bob\n";
    if (x > y)
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