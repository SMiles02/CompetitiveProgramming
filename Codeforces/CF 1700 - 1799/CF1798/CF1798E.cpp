#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, mx = 0;
    cin >> n;
    int a[n], is_perfect[n + 1], ans[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    is_perfect[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        // computing stuff
        if (i + a[i] + 1 <= n && is_perfect[i + a[i] + 1] != -1)
            is_perfect[i] = is_perfect[i + a[i] + 1] + 1;
        else
            is_perfect[i] = -1;
        // check ans
        if (i != n - 1) {
            if (is_perfect[i + 1] == a[i]) // no changes needed
                ans[i] = 0;
            else if (is_perfect[i + 1] >= 0) // we can just change a[i] to is_perfect[i + 1]
                ans[i] = 1;
            else if (mx >= a[i] - 1) // change a[i + 1] to end before is_perfect[a[i] - 1]
                ans[i] = 1; // note: this is probably where the error is
            else // just change a[i] to 1 and a[i + 1] to n - i - 2
                ans[i] = 2;
        }
        // mx = max(mx, is_perfect[i]);
        // cout << i << ": " << is_perfect[i] << "\n";
    }
    for (int i = 0; i < n - 1; ++i)
        cout << ans[i] << " ";
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