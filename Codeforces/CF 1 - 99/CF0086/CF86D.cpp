#include <bits/stdc++.h>
using namespace std;

const int A = 1e6 + 1, N = 2e5 + 1, S = 448;
int a[N], f[A];
long long ans[N];
vector<array<int, 3>> solve[S + 3]; 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r;
    long long cur;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        solve[l / S].push_back({r, l, i});
    }
    for (int i = 0; i < S + 3; ++i) {
        sort(solve[i].begin(), solve[i].end());
        l = r = i * S + (i == 0);
        if (l > n)
            break;
        ++f[a[l]];
        cur = a[l];
        for (auto j : solve[i]) {
            while (r < j[0]) {
                ++f[a[++r]];
                cur += (2LL * f[a[r]] - 1) * a[r];
            }
            while (l < j[1]) {
                cur -= (2LL * f[a[l]] - 1) * a[l];
                --f[a[l++]];
            }
            while (l > j[1]) {
                ++f[a[--l]];
                cur += (2LL * f[a[l]] - 1) * a[l];
            }
            ans[j[2]] = cur;
        }
        while (l <= r) {
            cur -= (2LL * f[a[l]] - 1) * a[l];
            --f[a[l++]];
        }
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
    return 0;
}