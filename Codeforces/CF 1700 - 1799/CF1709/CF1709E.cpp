#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int a[N], x[N], sub[N], ans;
vector<int> e[N];
bitset<N> black, changed;
map<int, int> m;
map<array<int, 2>, int> mp;
bool issue;

void sub_dfs(int c, int p) {
    sub[c] = 1;
    for (int i : e[c])
        if (!black[i] && i != p) {
            sub_dfs(i, c);
            sub[c] += sub[i];
        }
}

int find_centroid(int c, int p, int t) {
    for (int i : e[c])
        if (!black[i] && i != p && sub[i] > t)
            return find_centroid(i, c, t);
    return c;
}

void dfs(int c, int p, int r, int k) {
    if (changed[c])
        return;
    x[c] = x[p] ^ a[c];
    ++m[x[c]];
    ++mp[{x[c], r}];
    issue |= (m[x[c] ^ k] - mp[{x[c] ^ k, r}] > 0);
    for (int i : e[c])
        if (!black[i] && i != p)
            dfs(i, c, r, k);
}

void solve(int c) {
    sub_dfs(c, 0);
    int centroid = find_centroid(c, 0, sub[c] / 2);
    black[centroid] = 1;
    for (int i : e[centroid])
        if (!black[i])
            solve(i);
    m.clear();
    mp.clear();
    x[centroid] = a[centroid];
    issue = false;
    ++m[x[centroid]];
    for (int i : e[centroid])
        if (!black[i])
            dfs(i, centroid, i, a[centroid]);
    if (issue) {
        ++ans;
        changed[centroid] = true;
    }
    black[centroid] = 0;
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    solve(1);
    cout << ans;
    return 0;
}