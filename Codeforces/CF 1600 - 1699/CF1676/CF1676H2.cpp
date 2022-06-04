#include <bits/stdc++.h>
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

void solve() {
    int n;
    cin >> n;
    BIT bit(n);
    int a[n];
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += bit.query(a[i], n);
        bit.update(a[i], 1);
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