#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int dp[N][2];
vector<int> e[N];

void dfs(int c) {
    dp[c][1] = 1;
    for (int i : e[c]) {
        dfs(i);
        dp[c][0] += max(dp[i][0], dp[i][1]);
        dp[c][1] = max(dp[c][1], dp[i][1] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        e[p].push_back(i);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}