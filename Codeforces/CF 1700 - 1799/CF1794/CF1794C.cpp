#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l = 0;
    cin >> n;
    int a[n];
    for (int r = 0; r < n; ++r) {
        cin >> a[r];
        while (a[l] < r - l + 1)
            ++l;
        cout << r - l + 1 << " ";
    }
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