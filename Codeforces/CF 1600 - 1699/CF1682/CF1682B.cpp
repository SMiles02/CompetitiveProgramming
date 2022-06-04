#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = (1 << 20) - 1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        if (a[i] != i)
            x &= i;
    cout << x << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}