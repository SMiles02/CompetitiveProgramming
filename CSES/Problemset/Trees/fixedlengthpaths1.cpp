#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> e[N];
int k, sub[N], dp_size;
long long ans;
bitset<N> black;

void sub_dfs(int c, int p) {
    sub[c] = 1;
    for (int i : e[c]) {
        if (i != p && !black[i]) {
            sub_dfs(i, c);
            sub[c] += sub[i];
        }
    }
}

int find_centroid(int c, int p, int tree_size) {
    for (int i : e[c]) {
        if (i == p || black[i]) continue;
        if (sub[i] * 2 > tree_size) {
            return find_centroid(i, c, tree_size);
        }
    }
    return c;
}

void dfs(int c, int p, int h, vector<int>& dp, bool update_dp) {
    if (h > k) {
        return;
    }
    if (update_dp) {
        ++dp[h];
    }
    else if (k - h < dp.size()) {
        ans += dp[k - h];
    }
    for (int i : e[c]) {
        if (i != p && !black[i]) {
            dfs(i, c, h + 1, dp, update_dp);
        }
    }
}

void solve(int c) {
    sub_dfs(c, -1);
    int centroid = find_centroid(c, -1, sub[c]);
    black[centroid] = 1;
    dp_size = min(k, sub[c]) + 1;
    vector<int> dp(dp_size + 1);
    dp[0] = 1;
    for (int i : e[centroid]) {
        if (!black[i]) {
            dfs(i, centroid, 1, dp, false);
            dfs(i, centroid, 1, dp, true);
        }
    }
    for (int i : e[centroid]) {
        if (!black[i]) {
            solve(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >> k;
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    solve(1);
    cout << ans;
    return 0;
}