#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, k, mn, mx;
    cin >> n >> x;
    long long ans = 0;
    set<int> s;
    vector<array<int, 2>> range(x + 1, {x, 1});
    mn = x;
    mx = 1;
    while (n--) {
        cin >> k;
        if (s.upper_bound(k) != s.end()) {
            range[k] = {*s.upper_bound(k), *--s.end()};
            mx = max(mx, k);
        }
        s.insert(k);
    }
    for (int i = 1; i <= x; ++i) {
        mn = min(mn, range[i - 1][0]);
        mx = max({mx, range[i - 1][1], i});
        if (i <= mn)
            ans += x - mx + 1;
    }
    cout << ans;
    return 0;
}