#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1, X = 32;
int a[N], sub[N];
vector<int> e[N], ans;
vector<array<bool, X>> dp[N];
array<bool, X> tmp, tot[N];

void dfs(int c) {
    sub[c] = 1;
    dp[c].push_back(tmp);
    dp[c][0][a[c]] = true;
    for (int i = 0; i < e[c].size(); ++i) {
        dfs(e[c][i]);
        sub[c] += sub[e[c][i]];
        array<bool, X> cur = tmp;
        for (int j = 0; j < X; ++j)
            if (dp[c][i][j])
                for (int k = 0; k < X; ++k)
                    if (tot[e[c][i]][k])
                        cur[j ^ k] = true;
        dp[c].push_back(cur);
    }
    tot[c] = dp[c].back();
    if (sub[c] % 2 == 0)
        tot[c][0] = true;
}

void solve(int c, int trg) {
    if (trg == 0 && sub[c] % 2 == 0) {
        ans.push_back(c);
        ans.push_back(c);
        return;
    }
    int cur = trg;
    for (int i = sz(e[c]) - 1; i >= 0; --i) {
        for (int j = 0; j < 32; ++j)
            if (tot[e[c][i]][j] && dp[c][i][cur ^ j]) {
                solve(e[c][i], j);
                cur ^= j;
                break;
            }
        dp[c].pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < X; ++i)
        tmp[i] = false;
    int n, p;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        e[p].push_back(i);
    }
    if (n % 2 == 0) {
        cout << "2\n1 1";
        return 0;
    }
    dfs(1);
    if (tot[1][0]) {
        solve(1, 0);
        ans.push_back(1);
        ans.push_back(1);
        cout << ans.size() << "\n";
        for (int i : ans)
            cout << i << " ";
    }
    else
        cout << "-1\n";
    return 0;
}