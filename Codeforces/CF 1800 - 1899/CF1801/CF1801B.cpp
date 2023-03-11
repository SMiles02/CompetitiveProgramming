#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 1, INF = 2e9 + 1;
array<int, 2> a[N];

void solve() {
    int n, ans = INF, mx = -1, cur1, cur2, cur3;
    cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        s.insert(a[i][1]);
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1)
            mx = max(mx, a[i + 1][1]);
        cur1 = cur2 = cur3 = mx;
        s.erase(s.find(a[i][1]));
        if (i == 0) {
            ans = min(ans, abs(mx - a[i][0]));
            break;
        }
        if (s.lower_bound(a[i][0]) != s.end())
            cur1 = max(cur1, *s.lower_bound(a[i][0]));
        if (s.lower_bound(a[i][0]) != s.begin())
            cur2 = max(cur2, *(--s.lower_bound(a[i][0])));
        if (s.find(a[i][0]) != s.end())
            cur3 = max(cur3, a[i][0]);
        ans = min({ans, abs(cur1 - a[i][0]) + INF * (cur1 == -1), abs(cur2 - a[i][0]) + INF * (cur2 == -1), abs(cur3 - a[i][0]) + INF * (cur3 == -1)});
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}