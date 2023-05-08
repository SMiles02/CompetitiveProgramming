#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5e5;

void solve() {
    int n, k, ans = INF, cur_sum = 0, cur_cnt = 0;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
        cin >> a[i][0];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1];
        cur_sum += a[i][1] - a[i][0] + 1;
        ++cur_cnt;
        pq.push(a[i][1] - a[i][0] + 1);
        while (!pq.empty() && cur_sum - pq.top() >= k) {
            int without_cur = cur_sum - (a[i][1] - a[i][0] + 1);
            int how_many_more = max(k - without_cur, 1);
            ans = min(ans, cur_cnt * 2 + a[i][0] + how_many_more - 1);
            cur_sum -= pq.top();
            --cur_cnt;
            pq.pop();
        }
        if (cur_sum >= k) {
            int without_cur = cur_sum - (a[i][1] - a[i][0] + 1);
            int how_many_more = max(k - without_cur, 1);
            ans = min(ans, cur_cnt * 2 + a[i][0] + how_many_more - 1);
        }
    }
    if (ans == INF)
        ans = -1;
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