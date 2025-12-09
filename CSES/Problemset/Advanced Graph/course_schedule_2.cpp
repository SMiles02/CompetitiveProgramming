#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> to(n + 1), ans;
    vector<vector<int>> from(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        from[b].push_back(a);
        ++to[a];
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; ++i) {
        if (to[i] == 0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int x = pq.top();
        ans.push_back(x);
        pq.pop();
        for (int i : from[x]) {
            if (--to[i] == 0) {
                pq.push(i);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}