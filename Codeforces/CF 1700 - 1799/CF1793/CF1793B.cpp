// garbage problem

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    cout << (x - y) * 2 << "\n";
    for (int i = y; i <= x; ++i)
        cout << i << " ";
    for (int i = x - 1; i > y; --i)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}