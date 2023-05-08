#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    priority_queue<array<int, 2>> pq;
    vector<array<int, 2>> ans;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        if (k > 0)
            pq.push({k, i});
    }
    while (!pq.empty()) {
        auto [cnt, x] = pq.top();
        pq.pop();
        vector<array<int, 2>> tmp;
        while (!pq.empty() && cnt > 0) {
            auto [ec, y] = pq.top();
            pq.pop();
            if (--ec > 0) 
                tmp.push_back({ec, y});
            ans.push_back({x, y});
            --cnt;
        }
        if (cnt > 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (auto i : tmp)
            pq.push(i);
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i[0] << " " << i[1] << "\n";
    return 0;
}