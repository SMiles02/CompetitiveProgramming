#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll d(vector<int> &v, vector<int> &w) {
    ll d = 0;
    for (int i = 0; i < v.size(); ++i)
        d += abs(v[i] - w[i]);
    return d;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n * 2);
    for (int i = 0; i < n * 2; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    if (n == 1)
        cout << v[1] - v[0] << "\n";
    else if (n == 2) {
        vector<int> x(n * 2, 0), y(n * 2, 2), z(n * 2, -1);
        z[n * 2 - 1] = 2;
        cout << min({d(v, x), d(v, y), d(v, z)}) << "\n";
    }
    else if (n & 1) {
        vector<int> x(n * 2, 0);
        cout << d(v, x) << "\n";
    }
    else {
        vector<int> x(n * 2, 0), y(n * 2, -1);
        y[n * 2 - 1] = n;
        cout << min(d(v, x), d(v, y)) << "\n";
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