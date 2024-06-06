#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, cnt;
    cin >> n >> x >> y;
    vector<int> v(x), o, e;
    for (int i = 0; i < x; ++i) {
        cin >> v[i];
        --v[i];
    }
    sort(v.begin(), v.end());
    cnt = x;
    v.push_back(v[0]);
    for (int i = 1; i <= x; ++i) {
        if ((v[i] - v[i - 1] + n) % n != 1) {
            if (((v[i] - v[i - 1] + n - 1) % n) & 1) {
                o.push_back((v[i] - v[i - 1] + n - 1) % n);
            }
            else {
                e.push_back((v[i] - v[i - 1] + n - 1) % n);
            }
        }
    }
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    for (int i : o) {
        if (i / 2 <= y) {
            cnt += i;
            y -= i / 2;
        }
        else {
            cnt += y * 2;
            y = 0;
        }
    }
    for (int i : e) {
        cnt += min(i / 2, y) * 2;
        y -= min(i / 2, y);
    }
    cout << max(cnt - 2, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}