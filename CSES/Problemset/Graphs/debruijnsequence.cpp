#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 15) + 1;
vector<int> from[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= (1 << n); ++i) {
        from[i].push_back((i * 2) & ((1 << n) - 1));
        from[i].push_back(((i * 2) & ((1 << n) - 1)) + 1);
    }
    deque<int> ans = {1};
    while (!from[ans.back()].empty()) {
        int x = from[ans.back()].back();
        from[ans.back()].pop_back();
        ans.push_back(x);
    }
    for (int i = 0; i < n + (1 << n) - 1; ++i) {
        ans.push_front(ans.back());
        ans.pop_back();
        while (!from[ans.back()].empty()) {
            int x = from[ans.back()].back();
            from[ans.back()].pop_back();
            ans.push_back(x);
        }
    }
    for (int i = n - 1; i > 0; --i) {
        cout << min(ans[0] & (1 << i), 1);
    }
    for (int i : ans) {
        cout << (i & 1);
    }
    return 0;
}