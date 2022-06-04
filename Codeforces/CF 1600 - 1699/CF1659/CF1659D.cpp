#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, toSub = 0;
    ll s = 0;
    cin >> n;
    vector<int> c(n + 1), ans(n + 1), fix(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        s += c[i];
    }
    s /= n;
    for (int i = n; i > 0; --i) {
        toSub -= fix[i];
        c[i] -= toSub;
        if (s) {
            ++toSub;
            ++fix[i - s];
        }
        if (c[i] == i) {
            ans[i] = 1;
            --s;
        }
    }
    for (int i = 1; i <= n; ++i)
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