#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3e5 + 1;
int d[N];
ll dp[N][2];
vector<array<int, 2>> e[N];

void dfs(int c, int p) {
    ll cur = 0;
    vector<ll> v;
    for (auto i : e[c])
        if (i[0] != p) {
            dfs(i[0], c);
            if (d[i[0]] > 0)
                dp[i[0]][1] += max(i[1], 0);
            cur += dp[i[0]][0];
            // cout << i[0] << ": " << dp[i[0]][0] << " " << dp[i[0]][1] << "\n";
            v.push_back(max(0LL, dp[i[0]][1] - dp[i[0]][0]));
        }
    dp[c][0] = dp[c][1] = cur;
    if (d[c] > 0) {
        while (v.size() < d[c])
            v.push_back(0);
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < d[c] - 1; ++i)
            cur += v[i];
        dp[c][0] = dp[c][1] = cur;
        dp[c][0] += v[d[c] - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y, z;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    for (int i = 1; i < n; ++i) {
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    dfs(1, 0);
    cout << dp[1][0];
    return 0;
}