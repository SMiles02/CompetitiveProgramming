#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n;
    int p[n + 1], q[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    if (n == 1) {
        cout << "-1\n";
        return;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i)
        pq.push(i);
    for (int i = 1; i < n - 1; ++i) {
        if (pq.top() == p[i]) {
            x = pq.top();
            pq.pop();
            q[i] = pq.top();
            pq.pop();
            pq.push(x);
        }
        else {
            q[i] = pq.top();
            pq.pop();
        }
    }
    x = pq.top();
    pq.pop();
    y = pq.top();
    pq.pop();
    if (x == p[n - 1] || y == p[n]) {
        q[n - 1] = y;
        q[n] = x;
    }
    else {
        q[n - 1] = x;
        q[n] = y;
    }
    for (int i = 1; i <= n; ++i)
        cout << q[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}