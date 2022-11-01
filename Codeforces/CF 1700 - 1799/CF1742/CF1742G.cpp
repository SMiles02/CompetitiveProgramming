#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cur = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int t = 0; t < min(31, n); ++t) {
        int mx = -1, id;
        for (int i = 0; i < n; ++i)
            if (a[i] != -1 && (cur | a[i]) > mx) {
                id = i;
                mx = cur | a[i];
            }
        cout << a[id] << " ";
        cur = mx;
        a[id] = -1;
    }
    for (int i = 0; i < n; ++i)
        if (a[i] != -1)
            cout << a[i] << " ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}