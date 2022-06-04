#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n, rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) { for (int i=x;i<=n;i+=i&-i) bit[i]+=d; }
    int query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i) rtn+=bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x-1); }
};

void solve() {
    int n, m, k, tmp, ans, l, r, mid, needed = 0, sz;
    cin >> n >> k;
    vector<array<int, 2>> v;
    map<int, int> occ, mp;
    set<int> s;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
        ++occ[a[i]];
    }
    sz = s.size();
    v.push_back({0, 0});
    for (int i : s)
        v.push_back({occ[i], i});
    sort(v.begin(), v.end());
    m = v.size();
    BIT cost(m), reward(m);
    for (int i = 1; i < m; ++i) {
        cost.update(i, v[i][0]);
        reward.update(i, 1);
        mp[v[i][1]] = i;
    }
    ans = 1e9;
    for (int i = 0; i <= n; ++i) {
        if (k - needed < 0)
            continue;
        l = 0;
        r = m;
        while (l < r) {
            mid = l + (r - l) / 2 + 1;
            if (cost.query(mid) <= k)
                l = mid;
            else
                r = mid - 1;
        }
        ans = min(ans, i + reward.query(m) - reward.query(l) - i);
        if (s.count(i)) {
            cost.update(mp[i], -v[mp[i]][0]);
            reward.update(mp[i], -1);
        }
        else
            ++needed;
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