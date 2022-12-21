#include <bits/stdc++.h>
using namespace std;

const int N = 4004;
bitset<N> e[N];
int ec[N];

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 0; i <= n; ++i)
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


void solve() {
    int n, imperfect = -1;
    cin >> n;
    string s;
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ec[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                e[i][j] = 1;
                ++ec[i];
                dsu.unite(i, j);
            }
            else
                e[i][j] = 0;
        }
    }
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (dsu.connected(i, j) && !e[i][j] && i != j)
                imperfect = i;
        if (dsu.find_set(i) == i) {
            vector<int> w;
            for (int j = 0; j < n; ++j)
                if (dsu.connected(i, j))
                    w.push_back(j);
            v.push_back(w);
        }
    }
    if (v.size() == 1) { // if everything is in the same component, then of course the answer is 0
        cout << "0\n";
        return;
    }
    if (imperfect != -1) {
        vector<array<int, 2>> v;
        for (int i = 0; i < n; ++i)
            if (dsu.connected(imperfect, i))
                v.push_back({ec[i], i});
        sort(v.begin(), v.end());
        cout << "1\n" << v[0][1] + 1 << "\n";
        return;
    }
    // from now on, all components are cliques
    int mn = v[0].size(), id = 0;
    for (int i = 1; i < v.size(); ++i)
        if (v[i].size() < mn) {
            mn = v[i].size();
            id = i;
        }
    if (mn == 1) { // if there's a component of size 1, we can just flip the singular node in it, and the graph will be connected
        cout << "1\n" << v[id][0] + 1 << "\n";
        return;
    }
    if (v.size() > 2) { // if there are more than 2 components, we can flip 
        cout << "2\n" << v[0][0] + 1 << " " << v[1][0] + 1 << "\n";
        return;
    }
    // exactly 2 components, both cliques => flip all the nodes in the smaller one
    cout << v[id].size() << "\n";
    for (auto i : v[id])
        cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}