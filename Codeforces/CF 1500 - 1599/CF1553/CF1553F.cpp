#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct BIT {
    int n;
    ll rtn;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) { for (int i=x;i<=n;i+=i&-i) bit[i]+=d; }
    ll query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i) rtn+=bit[i];
        return rtn;
    }
    ll query(int x, int y) { return query(y) - query(x-1); }
};

const int N = 3e5 + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    BIT bit1(N), bit2(N);
    vector<int> a(n + 2);
    vector<ll> ans(n + 2);
    ll s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans[i] = ans[i - 1] + 1LL * a[i] * (i - 1) - bit1.query(a[i]) + s;
        for (int j = a[i]; j < N; j += a[i]) {
            bit1.update(j, a[i]);
            ans[i] -= 1LL * j * bit2.query(j, min(j + a[i], N) - 1);
        }
        bit2.update(a[i], 1);
        s += a[i];
        cout << ans[i] << " ";
    }
    return 0;
}