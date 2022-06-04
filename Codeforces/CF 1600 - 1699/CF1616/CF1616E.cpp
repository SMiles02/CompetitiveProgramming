#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct BIT {
    int n,rtn;
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

const ll INF = 1e18;

void solve() {
    int n;
    ll ans = INF, cur = 0, tmp;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    vector<int> v[26];
    BIT bit(n+1);
    for (int i = n - 1; i >= 0; --i)
        v[s[i] - 'a'].push_back(i);
    for (int i = 0; i < n; ++i) {
        tmp = INF;
        for (int j = 0; j < (t[i] - 'a'); ++j)
            if (!v[j].empty())
                tmp = min(tmp, (ll) v[j].back() + bit.query(v[j].back() + 1, n + 1) - i);
        ans = min(ans, cur + tmp);
        if (v[t[i] - 'a'].empty())
            break;
        cur += v[t[i] - 'a'].back() + bit.query(v[t[i] - 'a'].back() + 1, n + 1) - i;
        bit.update(v[t[i] - 'a'].back() + 1, 1);
        v[t[i] - 'a'].pop_back();
    }
    if (ans == INF)
        ans = -1;
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