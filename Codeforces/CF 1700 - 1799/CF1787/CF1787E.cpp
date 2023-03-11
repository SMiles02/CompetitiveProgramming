#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x, xr = 0, p, dn = 0;
    cin >> n >> k >> x;
    vector<int> v;
    vector<bool> taken(n + 1);
    for (int i = 1; i <= n; ++i) {
        xr ^= i;
        if ((i & (1 << __lg(x))) && v.size() < k) {
            v.push_back(i);
            taken[i] = true;
            taken[i ^ x] = true;
        }
    }
    if (((k & 1) && x != xr) || (!(k & 1) && xr != 0) || v.size() < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == x) {
            cout << "1 " << v[i] << "\n";
            ++dn;
        }
        else {
            cout << "2 " << v[i] << " " << (v[i] ^ x) << "\n";
            dn += 2;
        }
    }
    cout << n - dn << " ";
    taken[v[0]] = taken[v[0] ^ x] = 0;
    for (int i = 1; i <= n; ++i)
        if (!taken[i])
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