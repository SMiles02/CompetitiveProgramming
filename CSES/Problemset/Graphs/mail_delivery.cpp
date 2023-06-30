#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    vector<set<int>> s(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (e[i].size() & 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    deque<int> d = {1};
    while (true) {
        while (!e[d.back()].empty()) {
            int x = d.back(), y = e[x].back();
            e[x].pop_back();
            if (!s[x].count(y)) {
                s[x].insert(y);
                s[y].insert(x);
                d.push_back(y);
            }
        }
        bool found = false;
        int rot = 0;
        while (rot < d.size()) {
            if (!e[d.back()].empty()) {
                found = true;
                break;
            }
            d.push_front(d.back());
            d.pop_back();
            ++rot;
        }
        if (!found)
            break;
    }
    int rot = 0;
    while ((d.front() != 1 || d.back() != 1) && rot < m) {
        d.push_front(d.back());
        d.pop_back();
        ++rot;
    }
    if (d.size() == m + 1 && d.front() == 1 && d.back() == 1) {
        while (d.front() != 1 || d.back() != 1) {
            d.push_front(d.back());
            d.pop_back();
        }
        for (int i : d)
            cout << i << " ";
    }
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}