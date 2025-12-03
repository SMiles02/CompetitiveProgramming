#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 15;
vector<int> from[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 10;
        return 0;
    }
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        from[i].push_back((i * 2) & ((1 << (n - 1)) - 1));
        from[i].push_back(((i * 2) & ((1 << (n - 1)) - 1)) | 1);
    }
    deque<array<int, 2>> ans = {{0, 1}};
    while (ans.front()[1] != 1 || from[ans.back()[0]].size()) {
        int cur = ans.back()[0];
        if (from[cur].empty()) {
            ans.push_front(ans.back());
            ans.pop_back();
        }
        else {
            ans.push_back({from[cur].back(), 0});
            from[cur].pop_back();
        }
    }
    cout << string(n - 2, '0');
    for (auto [x, t] : ans) {
        cout << (x & 1);
    }
    return 0;
}