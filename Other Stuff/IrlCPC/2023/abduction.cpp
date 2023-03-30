#include <bits/stdc++.h>
using namespace std;

// post-contest notes:
// - don't fire the laser unless you have to
// aka only fire it greedily at the current segment starting at your current position if there are still aliens to be abducted there
// - account for firing the laser with the prefix sum +x -x trick

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n;
    cin >> k;
    int ans = 0;
    vector<int> p(n), v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    ans = v[0];
    p[0] = v[0];
    p[k] = -v[0];
    for (int i = 1; i < n; ++i) {
        p[i] += p[i - 1];
        int x = max(v[i] - p[i], 0);
        ans += x;
        p[i] += x;
        if (i + k < n)
            p[i + k] -= x;
    }
    cout << ans << "\n";
    return 0;
}

