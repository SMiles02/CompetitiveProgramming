#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, m, a[N];

bool ok(int x) {
    long long free = 1LL * n * (x / 2);
    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < m; ++i) {
        if (mp[a[i]] < x) {
            if ((x - (++mp[a[i]])) & 1)
                --free;
        }
        else
            ++cnt;
    }
    return (cnt <= free);
}

void solve() {
    int l = 1, r = 4e5, mid;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    while (l < r) {
        mid = l + (r - l) / 2;
        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}