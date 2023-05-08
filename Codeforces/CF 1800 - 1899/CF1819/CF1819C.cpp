#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
int sub[N];
vector<int> e[N], cd[N];
bitset<N> dp[2];

void dfs(int c, int p) {
    int cd = 0;
    sub[c] = 1;
    vector<vector<int>> v(2, vector<int>(2));
    for (int i : e[c])
        if (i != p) {
            dfs(i, c);
            ++sub[c];
            cd[c].push_back(i);
            ++v[dp[0][i]][dp[1][i]];
        }
    if (sub[c] == 1) {
        dp[0][c] = dp[1][c] = 1;
        return;
    }
    if (sub[c] == v[1][0] + v[1][1]) // starts here
        dp[0][c] = 1;
    else if (sub[c] == v[1][0] + v[1][1] + 1) {
        for (int i : cd[c])
            if (dp[0][i] == 0)
                for (int j : cd[i])
                    
    }
    if (sub[c] == v[0][1] + v[1][1]) // ends here
        dp[1][c] = 1;
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
    dfs(1, 0);
    if (dp[0][1] || dp[1][1])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}