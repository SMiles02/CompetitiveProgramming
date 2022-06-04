#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, d = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        if (((((s[i] - '0') + k) & 1) == 0) && d < k) {
            v[i] = 1;
            ++d;
        }
    v[n - 1] += k - d;
    for (int i = 0; i < n; ++i)
        cout << (((s[i] - '0') + k - v[i]) & 1);
    cout << "\n";
    for (int i : v)
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