#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, l, r, x, y;
    cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        p[k] = i;
    }
    l = x = 1;
    r = y = n;
    while (r - l > 2) {
        if (p[x] == l) {
            ++l;
            ++x;
        }
        else if (p[x] == r) {
            --r;
            ++x;
        }
        else if (p[y] == l) {
            ++l;
            --y;
        }
        else if (p[y] == r) {
            --r;
            --y;
        }
        else {
            cout << l << " " << r << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}