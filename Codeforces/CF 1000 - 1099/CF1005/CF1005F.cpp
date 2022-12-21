#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
int k, cnt, d[N], mx;
vector<array<int, 2>> e[N];
vector<int> past[N], levels[N];
vector<vector<bool>> ans;
vector<bool> cur;

void rec(int lvl, int i) {
    if (lvl == mx) {
        ans.push_back(cur);
        ++cnt;
        return;
    }
    if (i == levels[lvl].size()) {
        rec(lvl + 1, 0);
        return;
    }
    for (auto j : past[levels[lvl][i]]) {
        cur[j] = true;
        rec(lvl, i + 1);
        if (cnt == k)
            return;
        cur[j] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m >> k;
    cur.resize(m, false);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        e[x].push_back({y, i});
        e[y].push_back({x, i});
    }
    for (int i = 2; i <= n; ++i)
        d[i] = -1;
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        levels[d[x]].push_back(x);
        for (auto i : e[x]) {
            if (d[i[0]] == -1) {
                d[i[0]] = d[x] + 1;
                q.push(i[0]);
                if (x == 1)
                    cur[i[1]] = true;
            }
            else if (d[i[0]] + 1 == d[x])
                past[x].push_back(i[1]);
        }
    }
    mx = d[x] + 1;
    rec(2, 0);
    cout << cnt << "\n";
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < m; ++j)
            cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}