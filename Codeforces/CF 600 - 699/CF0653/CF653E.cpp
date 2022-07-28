#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};


const int N = 3e5 + 3;
int p[N];
vector<int> v[N];
bitset<N> cant;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, x, y, cnt = 0;
    cin >> n >> m >> k;
    DSU dsu(n);
    for (int i = 1; i <= n; ++i) {
        v[i].push_back(1);
        v[i].push_back(n + 1);
        if (i > 1)
            v[i].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        if (x == 1 || y == 1)
            cant[x + y - 1] = 1;
    }
    if (n - v[1].size() + 1 < k) {
        cout << "impossible";
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        sort(v[i].begin(), v[i].end());
        for (int j = 1; j < v[i].size(); ++j)
            if (v[i][j - 1] + 1 < v[i][j]) {
                dsu.unite(i, v[i][j - 1] + 1);
                ++p[v[i][j - 1] + 1];
                --p[v[i][j] - 1];
            }
    }
    for (int i = 2; i < n; ++i) {
        p[i] += p[i - 1];
        if (p[i] > 0)
            dsu.unite(i, i + 1);
    }
    for (int i = 2; i <= n; ++i)
        if (cant[i] == 0 && !dsu.connected(1, i)) {
            dsu.unite(1, i);
            ++cnt;
        }
    if (cnt > k || dsu.rk[dsu.find_set(1)] < n)
        cout << "impossible";
    else
        cout << "possible";
    return 0;
}