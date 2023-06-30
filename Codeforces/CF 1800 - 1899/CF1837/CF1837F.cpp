#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    long long l = 1, r = 1e15, m;
    while (l < r) {
        m = l + (r - l) / 2;
        bool found_ans = false;
        vector<int> max_pref(n + 1), max_suf(n + 2);
        long long sum = 0;
        priority_queue<int> pq;
        for (int i = 1; i <= n; ++i) {
            if (sum + a[i] > m && !pq.empty() && a[i] < pq.top()) {
                sum -= pq.top();
                pq.pop();
            }
            if (sum + a[i] <= m) {
                sum += a[i];
                pq.push(a[i]);
            }
            max_pref[i] = pq.size();
        }
        sum = 0;
        while (!pq.empty())
            pq.pop();
        for (int i = n; i > 0; --i) {
            if (sum + a[i] > m && !pq.empty() && a[i] < pq.top()) {
                sum -= pq.top();
                pq.pop();
            }
            if (sum + a[i] <= m) {
                sum += a[i];
                pq.push(a[i]);
            }
            max_suf[i] = pq.size();
        }
        for (int i = 1; i <= n + 1; ++i)
            found_ans |= max_pref[i - 1] + max_suf[i] >= k;
        if (found_ans)
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}