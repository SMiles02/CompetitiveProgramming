#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5 + 1;
int c[N];
vector<array<int, 2>> v[N];

void solve() {
    int n, k, ans = 1e9, mx = 1e5, x;
    bool ok = true;
    cin >> n >> k;
    int a[n];
    array<int, 2> tmp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i]];
        v[a[i] / 2].push_back({i, a[i]});
    }
    for (int mn = 1e5; mn >= 0; --mn) {
        while (!v[mn].empty() && ok) {
            tmp = v[mn].back();
            v[mn].pop_back();
            --c[tmp[1]];
            ++c[mn];
            if (mn != a[tmp[0]] / k)
                v[a[tmp[0]] / (a[tmp[0]] / mn + 1)].push_back({tmp[0], mn});
        }
        if (mn <= a[0]) {
            while (c[mx] == 0)
                --mx;
            ans = min(ans, mx - mn);
        }
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