#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int ans[N];
vector<int> e[N];

void dfs(int c) {
    for (int i : e[c]) {
        if (ans[i] == 0) {
            ans[i] = 3 - ans[c];
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 0) {
            ans[i] = 1;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : e[i]) {
            if (ans[i] == ans[j]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}