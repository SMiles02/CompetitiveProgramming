#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, l = 0, r = 1e9, cnt, x, y, curL = 0, cur;
    cin >> n >> k;
    vector<array<int, 2>> ans;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    cnt = (n + k + 1) / 2;
    for (int i = 0; i + cnt - 1 < n; ++i)
        if (b[i + cnt - 1] - b[i] < r - l) {
            l = b[i];
            r = b[i + cnt - 1];
        }
    cout << l << " " << r << "\n";
    for (int i = 0; i + 1 < k; ++i) {
        cur = curL - 1;
        x = y = 0;
        while (x <= y) {
            ++cur;
            if (l <= a[cur] && a[cur] <= r)
                ++x;
            else
                ++y;
        }
        ans.push_back({curL, cur});
        cout << curL + 1 << " " << cur + 1 << "\n";
        curL = cur + 1;
    }
    cout << curL + 1 << " " << n << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}