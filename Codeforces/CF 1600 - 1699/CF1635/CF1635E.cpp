#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int col[N], to[N], ans[N];
bool ok = 1;
vector<int> from[N];
vector<array<int, 2>> e[N];

void dfs(int c, int x) {
    col[c] = x;
    for (auto i : e[x]) {
        if (!col[i[0]])
            dfs(i[0], 3 - x);
        else if (col[i[0]] == x)
            ok = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, t, x, y;
    cin >> n >> m;
    while (m--) {
        cin >> t >> x >> y;
        e[x].push_back({y, t});
        e[y].push_back({x, t});
    }
    for (int i = 1; i <= n; ++i)
        if (!col[i])
            dfs(i, 1);
    for (int i = 1; i <= n; ++i)
        if (col[i] == 1)
            for (auto j : e[i]) {
                if (j[1] == 1) {
                    ++to[j[0]];
                    from[i].push_back(j[0]);
                }
                else {
                    ++to[i];
                    from[j[0]].push_back(i);
                }
            }
    t = 1;
    stack<int> s;
    for (int i = 1; i <= n; ++i)
        if (to[i] == 0)
            s.push(i);
    while (!s.empty()) {
        x = s.top();
        s.pop();
        ans[x] = t++;
        for (int i : from[x]) 
            if (--to[i] == 0)
                s.push(i);
    }
    if (!ok || t < n) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        if (col[i] == 1)
            cout << "L ";
        else
            cout << "R ";
        cout << ans[i] << "\n";
    }
    return 0;
}