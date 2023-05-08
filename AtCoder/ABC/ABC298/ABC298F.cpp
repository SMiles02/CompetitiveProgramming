#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> a(n + 1), b(n + 1);
    vector<vector<int>> r(n + 1);
    map<int, int> s, t;
    vector<int> u;
    map<array<int, 2>, int> c;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (s.find(x) == s.end())
            s[x] = s.size();
        if (t.find(y) == t.end())
            t[y] = t.size();
        x = s[x];
        y = t[y];
        u.push_back(y);
        r[x].push_back(y);
        a[x] += z;
        b[y] += z;
        c[{x, y}] = z;
    }
    vector<array<ll, 2>> t2;
    for (auto i : t)
        t2.push_back({b[i.second], i.second});
    sort(t2.rbegin(), t2.rend());
    for (int i = 0; i <= n; ++i) {
        for (auto j : r[i])
            ans = max(ans, a[i] + b[j] - c[{i, j}]);
        for (auto j : t2)
            if (c.find({i, (int)j[1]}) == c.end()) {
                ans = max(ans, a[i] + b[j[1]]);
                break;
            }
    }
    cout << ans;
    return 0;
}