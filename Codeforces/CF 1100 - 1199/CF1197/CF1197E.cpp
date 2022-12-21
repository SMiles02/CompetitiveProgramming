#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

const array<int, 2> INF = {1000000001, 0};

array<int, 2> combine(array<int, 2> a, array<int, 2> b) {
    if (a[0] == b[0])
        return {a[0], add(a[1], b[1])};
    return min(a, b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y, mx = 0;
    cin >> n;
    array<int, 2> ans = INF, mini = INF, cur, tmp;
    set<int> s;
    map<int, vector<int>> start_points;
    map<int, array<int, 2>> dp;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        mx = max(mx, y);
        s.insert(x);
        s.insert(y);
        dp[x] = dp[y] = ans;
        start_points[y].push_back(x);
    }
    for (int i : s) {
        mini = combine(mini, dp[i]);
        cur = mini;
        if (cur == INF)
            cur = {0, 1};
        cur[0] += i;
        for (int j : start_points[i]) {
            if (j > mx)
                ans = combine(ans, cur);
            else {
                tmp = {cur[0] - j, cur[1]};
                dp[j] = combine(dp[j], tmp);
            }
        }
    }
    cout << ans[1];
    return 0;
}