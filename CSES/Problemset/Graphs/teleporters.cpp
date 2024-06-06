#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int to[N];
vector<int> from[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        from[x].push_back(y);
        ++to[y];
    }
    bool ok = (to[1] + 1 == from[1].size()) & (to[n] == from[n].size() + 1);
    for (int i = 2; i < n; ++i) {
        ok &= to[i] == from[i].size();
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    deque<int> ans = {1};
    while (!from[ans.back()].empty()) {
        int x = from[ans.back()].back();
        from[ans.back()].pop_back();
        ans.push_back(x);
    }
    for (int i = 0; i < max(n, m); ++i) {
        ans.push_front(ans.back());
        ans.pop_back();
        while (!from[ans.back()].empty()) {
            int x = from[ans.back()].back();
            from[ans.back()].pop_back();
            ans.push_back(x);
        }
    }
    for (int i = 0; i < m && (ans[0] != 1 || ans.back() != n); ++i) {
        ans.push_front(ans.back());
        ans.pop_back();
    }
    if (ans.size() != m + 1 && ans[0] == 1 && ans.back() == n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}