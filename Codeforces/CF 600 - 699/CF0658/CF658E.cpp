#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

int b, c;

ll cost(int x, int y) {
    return 1LL * ((y - x) / 5) * b + ((y - x) % 5) * c;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    ll ans = 1e18;
    cin >> n >> k >> b >> c;
    b = min(b, c * 5);
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i)
        a[i] -= a[0];
    for (int j = 0; j < 5; ++j) {
        int last;
        ll cur = 0;
        vector<deque<int>> d(5);
        vector<int> v(5);
        for (int i = 0; i < n; ++i) {
            d[a[i] % 5].push_front(a[i]);
            int t = a[i] + ((j + 5 - (a[i] % 5)) % 5);
            if (i == k - 1) {
                for (int x = 0; x < 5; ++x) {
                    v[x] = d[x].size();
                    for (int y : d[x])
                        cur += cost(y, t);
                }
                ans = min(ans, cur);
                last = t;
            }
            else if (i >= k) {
                cur += cost(last, t) * k + cost(a[i], t) - cost(d[a[i] % 5][v[a[i] % 5]], t);
                while (true) {
                    vector<array<ll, 2>> p, q;
                    for (int x = 0; x < 5; ++x) {
                        if (v[x] > 0)
                            p.push_back({cost(d[x][v[x] - 1], t), x});
                        if (v[x] < d[x].size())
                            q.push_back({cost(d[x][v[x]], t), x});
                    }
                    sort(p.rbegin(), p.rend());
                    sort(q.begin(), q.end());
                    if (q[0][0] < p[0][0]) {
                        cur += q[0][0] - p[0][0];
                        ++v[q[0][1]];
                        --v[p[0][1]];
                    }
                    else
                        break;
                }
                ans = min(ans, cur);
            }
        }
    }
    cout << ans;
    return 0;
}