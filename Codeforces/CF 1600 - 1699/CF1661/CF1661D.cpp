#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll ans = 0, tot = 0, cnt = 0, tmp = 0, x;
    vector<ll> b(n), close(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = n - 1; i >= 0; --i) {
        tot -= cnt;
        cnt -= close[i];
        b[i] -= tot;
        if (b[i] <= 0)
            continue;
        if (i >= k) {
            x = (b[i] + k - 1) / k;
            tot += x * k;
            cnt += x;
            ans += x;
            close[i - k] += x;
        }
        else
            tmp = max(tmp, (b[i] + i) / (i + 1));
    }
    cout << ans + tmp;
    return 0;
}