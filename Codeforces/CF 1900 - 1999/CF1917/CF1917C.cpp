#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int n, k, d, ans, cnt = 0;
    cin >> n >> k >> d;
    vector<int> a(n + 1), v(k);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
    }
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > i) {
            continue;
        }
        int tot = 0, x, y, d;
        for (int j = 0; j < k; ++j) {
            tot += v[j] >= i;
        }
        if (tot == 0) {
            continue;
        }
        if (i == a[i]) {
            x = 0;
        }
        else {
            if ((i - a[i]) % tot == 0) {
                x = ((i - a[i]) / tot - 1) * tot;
                d = tot;
            }
            else {
                x = ((i - a[i]) / tot) * tot;
                d = (i - a[i]) % tot;
            }
            // if (i == 5) {
            //     cerr << tot << " " << x << "\n";
            // }
            while (true) {
                ++x;
                if (v[(x - 1) % k] >= i) {
                    --d;
                    if (d == 0) {
                        break;
                    }
                }
            }
        }
        y = x;
        while (true) {
            ++y;
            if (v[(y - 1) % k] >= i) {
                break;
            }
        }
        // cout << i << ": " << x << " " << y << "\n";
        ++m[x];
        --m[y];
    }
    ans = (d - 1) / 2;
    for (auto i : m) {
        cnt += i.second;
        if (i.first + 1 <= d) {
            ans = max(ans, cnt + (d - i.first - 1) / 2);
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