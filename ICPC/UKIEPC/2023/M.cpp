#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; k += 2) {
                if (j > 0 && k == 0) {
                    continue;
                }
                int cur = a * 2 + (k / 2) * 3 + j * 2;
                ans = max(ans, cur);
            }
        }
    }
    cout << ans;
    return 0;
}