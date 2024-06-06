#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, k, cur = 0;
    cin >> n >> x;
    priority_queue<int> pq;
    while (n--) {
        cin >> k;
        if (cur >= k) {
            cur -= k;
            pq.push(k);
        }
        else if (!pq.empty() && pq.top() > k) {
            cur += pq.top() - k;
            pq.pop();
            pq.push(k);
        }
        cur += x;
    }
    cout << pq.size() << "\n";
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