#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = -1, k;
    cin >> n;
    map<int, int> m;
    while (n--) {
        cin >> k;
        if (++m[k] == 3)
            ans = k;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}