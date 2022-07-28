#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, L = 19;
int h[N], pt[N], tin[N], tout[N], t, up[L][N];
vector<int> e[N];

void dfs(int c, int p, int x) {
    up[0][c] = p;
    for (int i = 1; i < L; ++i)
        up[i][c] = up[i - 1][up[i - 1][c]];
    h[c] = x;
    tin[c] = ++t;
    for (int i : e[c])
        if (i != p) {
            dfs(i, c, x + 1);
            pt[i] = c;
        }
    tout[c] = ++t;
}

bool is_ancestor(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

bool solve_query() {
    int k;
    cin >> k;
    array<int, 2> a[k];
    for (int i = 0; i < k; ++i) {
        cin >> a[i][1];
        a[i][0] = h[a[i][1]];
    }
    if (k == 1)
        return true;
    sort(a, a + k);
    int pc = -1;
    for (int i = 1; i < k; ++i)
        if (!is_ancestor(a[i - 1][1], a[i][1])) {
            pc = a[i][1];
            break;
        }
    if (pc == -1) // a perfect chain
        return true;
    if (!is_ancestor(a[0][1], pc)) { // two separate disjoint chains
        int ep1 = a[0][1], ep2 = pc;
        for (int i = 1; i < k; ++i) {
            if (a[i][1] == ep1 || a[i][1] == ep2)
                continue;
            if (is_ancestor(ep1, a[i][1]))
                ep1 = a[i][1];
            else if (is_ancestor(ep2, a[i][1]))
                ep2 = a[i][1];
            else
                return false;
        }
        return true;
    }
    int cur = a[1][1];
    for (int i = L - 1; i >= 0; --i)
        if (tin[a[0][1]] < tin[up[i][cur]])
            cur = up[i][cur];
    if (is_ancestor(cur, pc)) // ensuring the split happens at the start
        return false;
    int ep1 = pc, ep2 = a[1][1];
    for (int i = 2; i < k; ++i) {
        if (a[i][1] == ep1 || a[i][1] == ep2)
            continue;
        if (is_ancestor(ep1, a[i][1]))
            ep1 = a[i][1];
        else if (is_ancestor(ep2, a[i][1]))
            ep2 = a[i][1];
        else
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, x, y;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0, 0);
    pt[1] = 0;
    cin >> q;
    while (q--) {
        if (solve_query())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}