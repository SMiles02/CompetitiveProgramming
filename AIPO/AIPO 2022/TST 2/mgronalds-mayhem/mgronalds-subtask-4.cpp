#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    int w[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    while (m--) {
        cin >> x >> y;
        if (!(w[x] + w[y])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}