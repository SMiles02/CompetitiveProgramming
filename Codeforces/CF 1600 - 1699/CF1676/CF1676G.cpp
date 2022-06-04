#include <bits/stdc++.h>
using namespace std;

const int N = 4001;
int s[N], ans = 0;
string col;
vector<int> e[N];

int dfs(int c) {
    if (col[c - 1] == 'W')
        s[c] = 1;
    else
        s[c] = -1;
    for (int i : e[c])
        s[c] += dfs(i);
    ans += (s[c] == 0);
    return s[c];
}

void solve() {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        e[x].push_back(i);
    }
    cin >> col;
    ans = 0;
    dfs(1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}