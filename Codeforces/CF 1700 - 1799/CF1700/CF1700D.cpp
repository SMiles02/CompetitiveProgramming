#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, cur, l, r, m, pt = 0;
    ll mn = 0;
    cin >> n;
    int a[n];
    ll s = 0, k, t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
        mn = max(mn, (s + i) / (i + 1));
    }
    k = (s + n - 1) / n;
    cin >> q;
    int ans[q];
    vector<array<int, 2>> v(q);
    for (int i = 0; i < q; ++i) {
        cin >> v[i][0];
        v[i][1] = i;
    }
    sort(v.begin(), v.end());
    vector<int> p(q);
    for (int i = n - 1; i > 0; --i) {
        t = (s + i - 1) / i;
        // cerr << t << ": ";
        if (v[q - 1][0] < t) {
            // cerr << "too late\n";
            continue;
        }
        l = 0;
        r = q - 1;
        while (l < r) {
            m = l + (r - l) / 2;
            if (v[m][0] < t)
                l = m + 1;
            else
                r = m;
        }
        // cerr << v[l][0] << "\n";
        ++p[l];
    }
    // cout << pq.size() << " " << n - 1 << "!\n";
    cur = n;
    for (int i = 0; i < q; ++i) {
        cur -= p[i];
        if (1LL * n * v[i][0] < k || v[i][0] < mn)
            ans[v[i][1]] = -1;
        else
            ans[v[i][1]] = cur;
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
    return 0;
}