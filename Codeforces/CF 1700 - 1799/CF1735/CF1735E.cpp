#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, d1[N], d2[N], p, q, a[N * 2];
vector<array<int, 2>> v, w;
set<int> e[N * 2];
map<int, int> m;
map<array<int, 2>, int> mp;

void add_edge(int x, int y) {
    e[x].insert(y);
    e[y].insert(x);
}

void add_edge(int x, int y, int z) {
    e[x].insert(y);
    e[y].insert(x);
    mp[{x, y}] = mp[{y, x}] = z;
}

bool in_range(int l, int x, int r) {
    return (l <= x && x <= r);
}

void print_sol(int l, int r, int x, int y) {
    cout << "YES\n";
    vector<int> ans;
    int mini = min({x, y});
    for (int i = 0; i < p + q; ++i)
        e[i].clear();
    mp.clear();
    for (int i = 0; i < p; ++i) {
        if (in_range(l, x - v[i][0], r) && m[abs(x - v[i][0] - y)])
            add_edge(i, m[abs(x - v[i][0] - y)], x - v[i][0]);
        if (in_range(l, x + v[i][0], r) && m[abs(x + v[i][0] - y)])
            add_edge(i, m[abs(x + v[i][0] - y)], x + v[i][0]);
    }
    for (int i = 0; i < p; ++i)
        a[i] = v[i][1];
    for (int i = 0; i < q; ++i)
        a[p + i] = w[i][1];
    int cur, trg, mn;
    vector<int> t;
    for (int i = 0; i < p + q; ++i)
        if (e[i].size() == 1)
            t.push_back(i);
    while (!t.empty()) {
        cur = t.back();
        t.pop_back();
        if (e[cur].size() != 1)
            continue;
        trg = *e[cur].begin();
        e[cur].clear();
        e[trg].erase(cur);
        if (e[trg].size() == 1)
            t.push_back(trg);
        mn = min(a[cur], a[trg]);
        a[cur] -= mn;
        a[trg] -= mn;
        while (mn--)
            ans.push_back(mp[{cur, trg}]);
        mini = min(mini, ans.back());
    }
    for (int i : ans)
        cout << i - mini << " ";
    cout << "\n" << x - mini << " " << y - mini << "\n";
}

bool solve_pnts(int l, int r, int x, int y) {
    for (int i = 0; i < p + q; ++i)
        e[i].clear();
    for (int i = 0; i < p; ++i) {
        if (in_range(l, x - v[i][0], r) && m[abs(x - v[i][0] - y)])
            add_edge(i, m[abs(x - v[i][0] - y)]);
        if (in_range(l, x + v[i][0], r) && m[abs(x + v[i][0] - y)])
            add_edge(i, m[abs(x + v[i][0] - y)]);
    }
    vector<int> t;
    for (int i = 0; i < p + q; ++i) {
        if (e[i].size() == 1)
            t.push_back(i);
        else if (e[i].size() == 0)
            return false;
    }
    for (int i = 0; i < p; ++i)
        a[i] = v[i][1];
    for (int i = 0; i < q; ++i)
        a[p + i] = w[i][1];
    int cur, trg, mn;
    while (!t.empty()) {
        cur = t.back();
        t.pop_back();
        if (e[cur].size() != 1)
            continue;
        trg = *e[cur].begin();
        e[cur].clear();
        e[trg].erase(cur);
        if (e[trg].size() == 1)
            t.push_back(trg);
        mn = min(a[cur], a[trg]);
        a[cur] -= mn;
        a[trg] -= mn;
    }
    for (int i = 0; i < p + q; ++i)
        if (a[i] != 0)
            return false;
    print_sol(l, r, x, y);
    return true;
}

bool solve_pnt(int l, int r, int x) {
    if (solve_pnts(l, r, x, -d2[n - 1]))
        return true;
    if (solve_pnts(l, r, x, d2[n - 1]))
        return true;
    if (solve_pnts(l, r, x, r - d2[n - 1]))
        return true;
    if (solve_pnts(l, r, x, r + d2[n - 1]))
        return true;
    return false;
}

void build_vec(vector<array<int, 2>>& v, int d[]) {
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    sort(d, d + n);
    v.clear();
    v = {{d[0], 1}};
    for (int i = 1; i < n; ++i) {
        if (v.back()[0] == d[i])
            ++v.back()[1];
        else
            v.push_back({d[i], 1});
    }
}

void solve() {
    cin >> n;
    build_vec(v, d1);
    build_vec(w, d2);
    p = v.size();
    q = w.size();
    m.clear();
    for (int i = 0; i < q; ++i)
        m[w[i][0]] = p + i;
    for (int i = 0; i < n; ++i)
        if (solve_pnt(0, d1[n - 1] + d1[i], d1[i]))
            return;
    if (solve_pnt(0, d1[n - 1] - d1[0], -d1[0]))
        return;
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}