#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, cur;
    bool ok = true;
    cin >> n >> m >> k;
    cur = k;
    priority_queue<int> pq;
    int a[k];
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        pq.push(a[i]);
        if (pq.size() == 1LL * n * m - 2)
            ok = false;
        while (!pq.empty() && pq.top() == cur) {
            pq.pop();
            --cur;
        }
    }
    if (ok)
        cout << "YA\n";
    else
        cout << "TIDAK\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}