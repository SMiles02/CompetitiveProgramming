#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    map<long long, long long> m;
    while (q--) {
        int t, w;
        long long u, v;
        cin >> t;
        if (t == 1) {
            cin >> u >> v >> w;
            while (u != v) {
                if (u > v) {
                    swap(u, v);
                }
                m[v] += w;
                v /= 2;
            }
        }
        else {
            cin >> u >> v;
            long long ans = 0;
            while (u != v) {
                if (u > v) {
                    swap(u, v);
                }
                ans += m[v];
                v /= 2;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}