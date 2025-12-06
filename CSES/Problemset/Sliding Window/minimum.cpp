#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, x, a, b, c, ans = 0;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    deque<array<int, 2>> d;
    for (int i = 0; i < n; ++i) {
        while (!d.empty() && d.back()[0] >= x) {
            d.pop_back();
        }
        d.push_back({x, i});
        while (i - d.front()[1] >= k) {
            d.pop_front();
        }
        if (i + 1 >= k) {
            ans ^= d.front()[0];
        }
        x = (1LL * x * a + b) % c;
    }
    cout << ans;
    return 0;
}