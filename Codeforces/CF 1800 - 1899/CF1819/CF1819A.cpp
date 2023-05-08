#include <bits/stdc++.h>
using namespace std;

int calc_mex(int n, vector<int>& v) {
    int mex = 0;
    map<int, int> m;
    for (auto i : v)
        ++m[i];
    while (m[mex] > 0)
        ++mex;
    return mex;
}

void solve() {
    int n, mex;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    mex = calc_mex(n, v);
    if (mex == n)
        cout << "NO\n";
    else {
        int l = 1e9, r = -1e9;
        for (int i = 0; i < n; ++i)
            if (v[i] == mex + 1) {
                l = min(l, i);
                r = max(r, i);
            }
        for (int i = l; i <= r; ++i)
            v[i] = mex;
        if (calc_mex(n, v) == mex + 1)
            cout << "YES\n";
        else
            cout << "NO\n";
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