#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        for (int i = n - 4; i >= 2; --i)
            cout << i << " ";
        cout << "1 " << n - 3 << " " << n - 2 << " ";
    }
    else
        for (int i = n - 2; i >= 1; --i)
            cout << i << " ";
    cout << n - 1 << " " << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}