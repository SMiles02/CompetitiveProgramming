#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 1, B = 5, MOD = 1e9 + 7;
array<int, B> bases[N], dp[N], total_hash;
set<array<int, B>> ok;
vector<int> e[N], ans;

array<int, B> add(array<int, B> x, array<int, B> y) {
    for (int i = 0; i < B; ++i) {
        x[i] += y[i];
        if (x[i] >= MOD)
            x[i] -= MOD;
    }
    return x;
}

array<int, B> sub(array<int, B> x, array<int, B> y) {
    for (int i = 0; i < B; ++i) {
        x[i] -= y[i];
        if (x[i] < 0)
            x[i] += MOD;
    }
    return x;
}

array<int, B> mul(array<int, B> x, array<int, B> y) {
    for (int i = 0; i < B; ++i)
        x[i] = (1LL * x[i] * y[i]) % MOD;
    return x;
}

void dfs(int c, int p) {
    for (int i = 0; i < B; ++i)
        dp[c][i] = 1;
    for (int i : e[c])
        if (i != p) {
            dfs(i, c);
            dp[c] = add(dp[c], mul(dp[i], bases[1]));
        }
}

void solve(int c, int p, array<int, B> hashes) {
    if (ok.count(hashes))
        ans.push_back(c);
    for (int i : e[c])
        if (i != p)
            solve(i, c, add(dp[i], mul(sub(hashes, mul(dp[i], bases[1])), bases[1])));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < B; ++i)
        bases[0][i] = 1;
    for (int i = 0; i < B; ++i)
        bases[1][i] = uniform_int_distribution<int>(N, N * 10)(rng);;
    for (int i = 2; i < N; ++i)
        bases[i] = mul(bases[i - 1], bases[1]);
    int n, k, x, y;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> k;
        total_hash = add(total_hash, bases[k]);
    }
    for (int i = 0; i < n; ++i)
        ok.insert(add(total_hash, bases[i]));
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    solve(1, 0, dp[1]);
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << " ";
    return 0;
}