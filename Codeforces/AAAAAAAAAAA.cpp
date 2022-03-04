#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> e[N];
bitset<N> done;

void dfs(int c) {
    // cout << c << " ";
    done[c] = true;
    for (int i : e[c])
        if (!done[i])
            dfs(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
        if (!done[i]) {
            dfs(i);
            if (i != 1)
                ans.push_back(i);
        }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << "1 " << i << "\n";
    return 0;
}