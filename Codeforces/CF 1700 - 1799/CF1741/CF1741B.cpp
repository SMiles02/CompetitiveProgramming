#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 3)
        cout << "-1\n";
    else if (n & 1) {
        for (int i = 3; i <= n; ++i)
            cout << i << " ";
        cout << "1 2\n";
    }
    else {
        for (int i = n; i >= 1; --i)
            cout << i << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}