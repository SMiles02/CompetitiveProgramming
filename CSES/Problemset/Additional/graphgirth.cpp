#include <bits/stdc++.h>
using namespace std;

const int N = 2501;
vector<int> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = N;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> d(n + 1), p(n + 1);
        queue<int> q;
        d[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : e[x]) {
                if (d[y] && p[x] != y)
                    ans = min(ans, d[x] + d[y] - 1);
                if (!d[y]) {
                    d[y] = d[x] + 1;
                    p[y] = x;
                    q.push(y);
                }
            }
        }
    }
    if (ans == N)
        ans = -1;
    cout << ans;
    return 0;
}