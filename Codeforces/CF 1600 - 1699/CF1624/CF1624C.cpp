#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        while (k > n)
            k /= 2;
        ++v[k];
    }
    for (int i = n; i > 0; --i) {
        if (v[i] == 0) {
            cout << "NO\n";
            return;
        }
        v[i / 2] += v[i] - 1;
    }
    cout << "YES\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}