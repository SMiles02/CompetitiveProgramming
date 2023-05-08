#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;
bitset<N> dp[N];
int from[N];
vector<int> to[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        ++from[x];
        to[y].push_back(x);
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i)
        if (from[i] == 0)
            v.push_back(i);
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        dp[x][x] = 1;
        for (int i : to[x]) {
            if (--from[i] == 0)
                v.push_back(i);
            dp[i] |= dp[x];
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << dp[i].count() << " ";
    return 0;
}