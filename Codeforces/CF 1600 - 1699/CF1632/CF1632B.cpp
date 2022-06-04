#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    k = n - 1;
    while (__builtin_popcount(k) > 1)
        k -= k & -k;
    for (int i = 1; i < k; ++i)
        cout << i << " ";
    cout << "0 ";
    for (int i = k; i < n; ++i)
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