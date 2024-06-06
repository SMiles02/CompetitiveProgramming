#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = -1e15;

void solve() {
    int m, x, sum = 1;
    cin >> m >> x;
    vector<int> c(m), h(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> h[i];
        sum += h[i];
    }
    vector<ll> olddp(sum, INF), newdp(sum, INF);
    olddp[0] = newdp[0] = 0;
    for (int i = 0; i < m; ++i) {
        newdp = olddp;
        for (int j = h[i]; j < sum; ++j) {
            if (olddp[j - h[i]] >= c[i]) {
                newdp[j] = max(newdp[j], olddp[j - h[i]] - c[i]);
            }
        }
        for (int j = 0; j < sum; ++j) {
            if (newdp[j] >= 0) {
                newdp[j] += x;
            }
        }
        swap(olddp, newdp);
    }
    for (int i = sum - 1; i >= 0; --i) {
        if (olddp[i] >= 0) {
            cout << i << "\n";
            return;
        }
    }
    cout << "wtf\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}