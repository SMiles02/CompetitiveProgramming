#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ok(int n, vector<array<int, 2>> &a, ll x, ll y) {
    int done = 0;
    map<ll, priority_queue<ll>> p, q;
    map<array<ll, 2>, ll> c, d;
    for (auto i : a) {
        p[i[0]].push(i[1]);
        q[i[1]].push(i[0]);
    }
    while (done < n) {
        if (!p[x].empty()) {
            int t = p[x].top();
            p[x].pop();
            if (c[{x, t}] > 0) {
                --c[{x, t}];
                continue;
            }
            ++d[{x, t}];
            y -= t;
            ++done;
        }
        else if (!q[y].empty()) {
            int t = q[y].top();
            q[y].pop();
            if (d[{t, y}] > 0) {
                --d[{t, y}];
                continue;
            }
            ++c[{t, y}];
            x -= t;
            ++done;
        }
        else
            return false;
    }
    return true;
}

void solve() {
    int n, x = 0, y = 0;
    ll s = 0;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        s += 1LL * a[i][0] * a[i][1];
        x = max(x, a[i][0]);
        y = max(y, a[i][1]);
    }
    set<array<ll, 2>> ans;
    if (s % x == 0 && y <= s / x && ok(n, a, x, s / x))
        ans.insert({x, s / x});
    if (s % y == 0 && x <= s / y && ok(n, a, s / y, y))
        ans.insert({s / y, y});
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i[0] << " " << i[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}