#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, cur, mn = 50, tot = 0;
    cin >> n;
    while (n--) {
        cin >> k;
        tot += k & 1;
        cur = 1;
        while ((k & 1) == ((k / 2) & 1)) {
            k /= 2;
            ++cur;
        }
        mn = min(mn, cur);
    }
    if (tot & 1)
        cout << mn << "\n";
    else
        cout << "0\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}