#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, d;
    long long ans = 0, sum = 0;
    cin >> n >> m >> d;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        if (ai > 0) {
            sum += ai;
            pq.push(ai);
            if (pq.size() == m + 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        ans = max(ans, sum - 1LL * d * i);
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