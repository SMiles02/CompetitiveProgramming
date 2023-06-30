#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n], x = 0, y = 0;
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] > 0)
            pq.push({b[i], i});
        y += b[i];
    }
    if (x != y) {
        cout << -1;
        return 0;
    }
    vector<string> g(n, string(n, '.'));
    for (int i = 0; i < n; ++i) {
        vector<array<int, 2>> v;
        for (int j = 0; j < a[i]; ++j) {
            if (pq.empty()) {
                cout << -1;
                return 0;
            }
            auto [q, p] = pq.top();
            pq.pop();
            g[i][p] = 'X';
            if (--q > 0)
                v.push_back({q, p});
        }
        for (auto j : v)
            pq.push(j);
    }
    for (auto i : g)
        cout << i << "\n";
    return 0;
}