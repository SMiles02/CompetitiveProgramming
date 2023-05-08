#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
int n;
vector<int> e[N], v;

void read_pointless() {
    int pointless;
    cin >> pointless;
}

void query(int i) {
    cout << "+ " << i << endl;
    read_pointless();
}

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
}

void add_edges(int l, int r) {
    query(l + r);
    while (l < r) {
        e[l].push_back(r);
        e[r--].push_back(l++);
    }
}

void dfs(int c, int p = 0) {
    v.push_back(c);
    for (int i : e[c])
        if (i != p)
            dfs(i, c);
}

void solve() {
    int mx = 0, id;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    add_edges(1, n);
    add_edges(2, n);
    v.clear();
    dfs(1);
    for (int i = 2; i <= n; ++i) {
        int cur = query(1, i);
        if (cur > mx) {
            mx = cur;
            id = i;
        }
    }
    vector<int> ans1(n + 1), ans2(n + 1);
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        if (i != id)
            cur = query(id, i);
        ans1[i] = v[cur];
        ans2[i] = v[n - cur - 1];
    }
    cout << "!";
    for (int i = 1; i <= n; ++i)
        cout << " " << ans1[i];
    for (int i = 1; i <= n; ++i)
        cout << " " << ans2[i];
    cout << endl;
    read_pointless();
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}