#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r, x;
    cin >> n >> q;
    int a[n + 1], last_diff[n + 1];
    last_diff[1] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1])
            last_diff[i] = last_diff[i - 1];
        else
            last_diff[i] = i - 1;
    }
    while (q--) {
        cin >> l >> r >> x;
        if (a[r] != x)
            cout << r << "\n";
        else if (l <= last_diff[r])
            cout << last_diff[r] << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}