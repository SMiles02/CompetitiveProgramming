// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int a, b, c, d, k, x, ans;
    cin >> a >> b;
    ans = b - a;
    k = b;
    while (__builtin_popcount(k) > 1)
        k -= k & -k;
    for (int i = 0;; ++i)
        if ((1 << i) == k) {
            x = i;
            break;
        }
    for (int i = 0; i < b - a; ++i) {
        c = a + i;
        ans = min(ans, i + 1 + (b | c) - b);
        if ((b | c) == b) {
            ans = min(ans, i + 1);
            break;
        }
        d = b | c;
        for (int i = x - 1; i >= 0; --i)
            if ((d & (1 << i)) > 0 && (c & (1 << i)) == 0 && d - (1 << i) >= b)
                d -= (1 << i);
        ans = min(ans, d - b + i + 1);
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