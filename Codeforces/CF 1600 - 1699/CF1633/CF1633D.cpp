#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
int d[N];
bitset<N> dn;

void solve() {
    int n, k;
    cin >> n >> k;
    int b[n], c[n];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    if (k >= n * 12) {
        int s = 0;
        for (int i = 0; i < n; ++i)
            s += c[i];
        cout << s << "\n";
        return;
    }
    vector<int> dp(k + 1);
    for (int i = 0; i < n; ++i)
        for (int j = k; j >= d[b[i]]; --j)
            dp[j] = max(dp[j], dp[j - d[b[i]]] + c[i]);
    cout << dp[k] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, x;
    queue<int> q;
    q.push(1);
    dn[1] = 1;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 1; i <= x; ++i)
            if (x + x / i < N && !dn[x + x / i]) {
                dn[x + x / i] = 1;
                d[x + x / i] = d[x] + 1;
                q.push(x + x / i);
            }
    }
    cin >> t;
    while (t--)
        solve();
    return 0;
}