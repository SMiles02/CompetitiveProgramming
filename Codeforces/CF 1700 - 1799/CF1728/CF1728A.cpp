#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, mx = -1, ans;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            ans = i;
        }
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}