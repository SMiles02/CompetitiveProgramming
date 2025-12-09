#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 1;
vector<int> e[N], leaf;
 
void dfs(int c, int p = 0) {
    if (e[c].size() == 1)
        leaf.push_back(c);
    for (int i : e[c])
        if (i != p)
            dfs(i, c);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    leaf.push_back(leaf[0]);
    cout << leaf.size() / 2 << "\n";
    for (int i = 0; i < leaf.size() / 2; ++i)
        cout << leaf[i] << " " << leaf[i + leaf.size() / 2] << "\n";
    return 0;
}